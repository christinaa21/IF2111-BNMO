// rng, diner dash, and other games

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <math.h>

#include "./diner_dash.h"

boolean compare(char str1[], char str2[])
{
    boolean found = false, i = 0;
    while ((str1[i] != '\0' || str2[i] != '\0') && !found)
    {
        if (str1[i] != str2[i])
        {
            found = true;
        }
        i++;
    }

    return !found;
}

void createFood(PQElType *food, int id)
{
    srand(time(NULL));
    (*food).foodID = id;
    (*food).cookDuration = rand() % 4 + 2;
    (*food).stayDuration = (rand() * 5 + rand() * 2) % 4 + 2;
    (*food).price = rand() % 4 * 10000 + rand() % 9 * 1000 + (rand() % 9) * 100 + (rand() % 9) * 10 + (rand() % 9);
}
void DinerDash()
{
    // Kamus

    // Algoritma

    char input[100];
    char cook[] = "COOK", serve[] = "SERVE";
    int foodQueue = 0;
    int successfulServe = 0;
    int saldo = 0;

    printf("Selamat datang di Diner Dash\n\n");

    PQElType food[10];

    PrioQueue q;
    CreateQueuePQ(&q);
    for (int i = 0; i < 3; i++)
    {
        createFood(&food[i], i);
        enqueuePQ(&q, food[i]);
    }

    while (successfulServe <= 15 || foodQueue <= 7)
    {
    }

    printf("SALDO : %d\n", saldo);

    printf("Daftar pesanan: \n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");

    for (int i = IDX_HEAD(q); i != IDX_TAIL(q); i++)
    {
        // pengurangan cookDuration
        if (q.buffer[i].cookDuration > 0)
        {
            q.buffer[i].cookDuration--;
        }

        // pengurangan stayDuration
        else if (q.buffer[i].cookDuration == 0)
        {
            q.buffer[i].stayDuration--;
        }
    }

    for (int i = 0; i < lengthPQ(q); i++)
    {
        printf("M%d      | %d              | %d         | %d    \n", q.buffer[i].foodID + 1, q.buffer[i].cookDuration, q.buffer[i].stayDuration, q.buffer[i].price);
    }

    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
    displayTimePQ(q);
    // printf("M%d      | %d                 \n", HEAD(q).ID, HEAD(q).cookDuration);

    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("-----------------------------\n");
    displayStayPQ(q);
    // printf("M%d      | %d                \n", HEAD(q).ID, HEAD(q).stayDuration);

    // input command
    char command[6];
    char cookedFood[5];
    printf("Masukkan permintaan ('%s / %s' + ' ' + M {1 - 5}): ", cook, serve);
    scanf("%s %s", command, cookedFood);
    printf("\n");

    // baca sampe sebelum spasi

    printf("Command: %s\n", command);
    printf("cookedFood: %s\n", cookedFood);

    //  handle input command
    while (!(compare(command, cook) || compare(command, serve)))
    {
        otherCommand();
        printf("Masukkan command: ");
        scanf("%s %s", command, cookedFood);
    }

    while (!(compare(cookedFood, "M0") || compare(cookedFood, "M1") || compare(cookedFood, "M2") || compare(cookedFood, "M3") || compare(cookedFood, "M4") || compare(cookedFood, "M5")))
    {
        otherCommand();
        printf("Masukkan command: ");
        scanf("%s %s", command, cookedFood);
    }

    // mengubah cookedFood menjadi int

    int id = 0;
    for (int i = 1; cookedFood[i] != '\0'; i++)
    {
        id = id * 10 + (cookedFood[i] - '0');
    }

    printf("id: %d\n", id);

    // cook
    if (compare(command, cook))
    {
        enqueuePQ(&q, food[id]);
        printf("Makanan %s telah dimasukkan ke dalam antrian", cookedFood);

        foodQueue++;
    }

    // serve
    else if (compare(command, serve))
    {
        PQElType currentFood;
        PQElType servableFood;
        PQElType brokenFood;

        int i = IDX_HEAD(q);

        while (i != IDX_TAIL(q) + 1)
        {
            if (q.buffer[i].foodID == id)
            {
                currentFood = q.buffer[i];
            }
            i = (i + 1) % PQCAPACITY;
        }

        if (currentFood.cookDuration == 0)
        {
            if (currentFood.stayDuration > 0)
            {
                dequeueAtIdx(&q, &servableFood, i);
                printf("Berhasil mengantar M%s", servableFood.foodID);
                saldo += servableFood.price;
                successfulServe++;
            }

            else
            {
                printf("Makanan %s telah rusak", cookedFood);
                dequeueAtIdx(&q, &brokenFood, i);
            }
        }

        else
        {
            printf("Makanan %s belum siap disajikan", cookedFood);
        }

        // print queue
        // print makanan yang sedang dimasak
        // print makanan yang dapat disajikan
        // print saldo
    }

    printf("=============================================================================================");
}

// -	Terdapat 2 command yang dapat dilakukan pada game, yaitu COOK dan SERVE
// -	COOK merupakan command yang bertujuan untuk memasak makanan
// -	SERVE merupakan command yang bertujuan untuk menyajikan makanan kepada pelanggan.
// -	Permainan akan dimulai dengan 3 pelanggan. Setiap pelanggan hanya dapat memesan satu makanan. Untuk setiap makanan, terdapat informasi tentang ID makanan yang dihasilkan secara increment (M01, M02, M03, dst), durasi memasak, harga makanan, serta ketahanan makanan. Semua informasi tersebut akan didapatkan secara random dengan menggunakan random number generator. Durasi dan ketahanan makanan akan berkisar diantara 1-5. Sedangkan, harga makanan akan berkisar diantara 10000 - 50000.
// -	Kapasitas dari pemain adalah memasak 5 makanan dalam waktu yang sama. Pelanggan yang dilayani adalah pelanggan yang duluan memasuki antrian.
// -	Permainan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan.
// -	Pada setiap putaran, akan terdapat 1 pelanggan baru.
// -	Pada setiap putaran, seluruh durasi dari makanan yang sedang dimasak akan berkurang 1. Ketika durasi makanan mencapai 0, maka makanan sudah dapat di SERVE.
// -	Ketika makanan sudah di SERVE, maka makanan dapat diantar kepada pelanggan dan pelanggan dapat meninggalkan antrian. Setelah pelanggan meninggalkan antrian, maka pemain akan menerima uang
// -	SERVE hanya dapat digunakan untuk pesanan yang berada di paling depan.
// -	Skor akhir dari pemain adalah total uang yang diterima oleh pemain.