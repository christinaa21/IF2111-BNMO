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
    (*food).cookDuration = rand() % 4 + 1;
    (*food).stayDuration = (rand() * 5 + rand() * 2) % 4 + 1;
    (*food).price = (rand() % 4 + 1) * 10000 + rand() % 9 * 1000 + (rand() % 9) * 100 + (rand() % 9) * 10 + (rand() % 9);
}

void delay(int number_of_milliseconds)
{
    // Converting time into milli_seconds
    int milli_seconds = number_of_milliseconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void DinerDash()
{
    // Kamus

    // Algoritma

    // Inisialisasi
    char input[100];
    char cook[] = "COOK", serve[] = "SERVE";

    PrioQueue cookingAndServingQ;
    CreateQueuePQ(&cookingAndServingQ);

    PrioQueue waitingQ;
    CreateQueuePQ(&waitingQ);

    int foodQueue = 0;
    int successfulServe = 0;
    int saldo = 0;

    printf("Selamat datang di Diner Dash\n");

    PrioQueue food;
    CreateQueuePQ(&food);

    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        createFood(&food.buffer[i], i);
        enqueuePQ(&food, food.buffer[i]);
        enqueuePQ(&waitingQ, food.buffer[i]);
        delay(1000);
    }

    while (successfulServe < 15 && lengthPQ(cookingAndServingQ) < 7)
    {
        printf("SALDO : %d\n\n", saldo);

        PQElType brokenFood;

        if (!isEmptyPQ(cookingAndServingQ))
        {
            for (int i = IDX_HEAD(cookingAndServingQ); i != IDX_TAIL(cookingAndServingQ) + 1; i++)
            {
                // pengurangan cookDuration
                if (cookingAndServingQ.buffer[i].cookDuration > 0)
                {
                    cookingAndServingQ.buffer[i].cookDuration--;
                }

                // pengurangan stayDuration
                else if (cookingAndServingQ.buffer[i].cookDuration == 0)
                {
                    cookingAndServingQ.buffer[i].stayDuration--;

                    if (cookingAndServingQ.buffer[i].stayDuration == 0)
                    {
                        dequeueAtIdx(&cookingAndServingQ, &brokenFood, i);
                        printf("Makanan M%d telah rusak\n", brokenFood.foodID);
                    }
                }

                else
                {
                    cookingAndServingQ.buffer[i].cookDuration = 0;
                }
            }
        }

        printf("Daftar pesanan: \n");
        printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
        printf("--------------------------------------------\n");

        int len = lengthPQ(waitingQ);

        if (len > 0)
        {
            for (int i = 0; i < len; i++)
            {
                printf("M%d      | %d              | %d         | %d    \n", waitingQ.buffer[i].foodID, waitingQ.buffer[i].cookDuration, waitingQ.buffer[i].stayDuration, waitingQ.buffer[i].price);
            }
        }

        delay(1000);

        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n");
        printf("Makanan | Sisa durasi memasak\n");
        printf("-----------------------------\n");
        displayTimePQ(cookingAndServingQ);
        printf("\n");

        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan | Sisa ketahanan makanan\n");
        printf("-----------------------------\n");
        displayStayPQ(cookingAndServingQ);
        printf("\n");
        delay(500);

        // input command
        char command[6];
        char cookedFood[5];
        printf("Masukkan permintaan ('%s / %s' + ' ' + M {0 - %d}): ", cook, serve, len - 1);
        // scanf("%s %s", command, cookedFood);
        STARTINPUTKATA();
        while (!IsEOP())
        {
            printf("%s ", GetCC());
            ADVKATA();
        }
        printf("\n");

                //  validasi input command
        while (!(compare(command, cook) || compare(command, serve)))
        {
            otherCommand();
            printf("Masukkan command: ");
            scanf("%s %s", command, cookedFood);
        }

        while (!(compare(cookedFood, "M0") || compare(cookedFood, "M1") || compare(cookedFood, "M2") || compare(cookedFood, "M3") || compare(cookedFood, "M4") || compare(cookedFood, "M5") || compare(cookedFood, "M6") || compare(cookedFood, "M7") || compare(cookedFood, "M8") || compare(cookedFood, "M9")))
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

        delay(500);
        // COOK
        if (compare(command, cook))
        {
            enqueueCSQ(&cookingAndServingQ, food.buffer[id]);
            cookingAndServingQ.buffer[IDX_TAIL(cookingAndServingQ)].cookDuration++;
            printf("Makanan %s telah dimasukkan ke dalam antrian\n", cookedFood);

            foodQueue++;
        }
        // SERVE
        else if (compare(command, serve))
        {
            PQElType currentFood;
            PQElType servableFood;

            int i = IDX_HEAD(cookingAndServingQ);

            while (i != IDX_TAIL(cookingAndServingQ) + 1)
            {
                if (cookingAndServingQ.buffer[i].foodID == id)
                {
                    currentFood = cookingAndServingQ.buffer[i];
                    break;
                }
                i = (i + 1) % PQCAPACITY;
            }

            if (currentFood.cookDuration == 0)
            {
                if (currentFood.stayDuration > 0)
                {
                    if (currentFood.foodID == HEAD(cookingAndServingQ).foodID)
                    {
                        dequeueAtIdx(&cookingAndServingQ, &servableFood, i);
                        printf("Makanan M%d telah disajikan\n", servableFood.foodID);
                        saldo += servableFood.price;
                        successfulServe++; // increment successful serve
                    }

                    else
                    {
                        printf("Makanan %s belum dapat disajikan karena M%d belum disajikan\n", cookedFood, HEAD(cookingAndServingQ).foodID);
                    }
                }
            }

            else
            {
                printf("Makanan %s belum siap disajikan\n", cookedFood);
            }
        }

        // displayQueuePQ(cookingAndServingQ);
        printf("\n");

        printf("=============================================================================================\n\n");
        delay(500);
        if (len < 10)
        {
            createFood(&food.buffer[len], len);
            enqueuePQ(&food, food.buffer[len]);
            enqueuePQ(&waitingQ, food.buffer[len]);
        }
    }

    printf("Congratulation!\nYou've served %d food\n", successfulServe);
    printf("Game Over \n");
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