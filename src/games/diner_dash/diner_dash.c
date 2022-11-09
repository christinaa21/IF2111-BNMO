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

PQElType createFood(int id)
{
    PQElType food;
    srand(time(NULL));
    (food).foodID = id;
    (food).cookDuration = rand() % 5 + 1;
    (food).stayDuration = (rand() * 5 + rand() * 2) % 5 + 1;
    (food).price = (rand() % 4 + 1) * 10000 + rand() % 9 * 1000 + (rand() % 9) * 10;
    return food;
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
    char cook[] = "COOK", serve[] = "SERVE";

    List cookingQ, servingQ;
    cookingQ = MakeList();
    servingQ = MakeList();

    PrioQueue waitingQ;
    CreateQueuePQ(&waitingQ);

    int foodQueue = 0;
    int successfulServe = 0;
    int saldo = 0;
    boolean firstRound = true;

    printf("Selamat datang di Diner Dash\n");

    printf("\n");
    if (isEmptyPQ(waitingQ) && firstRound)
    {
        int i = IDX_HEAD(waitingQ);
        while (lengthPQ(waitingQ) < 3)
        {
            enqueuePQ(&waitingQ, createFood(i));
            delay(1000);
            i = (i + 1) % PQCAPACITY;
        }
        firstRound = false;
    }

    boolean gameOver = false;

    while (successfulServe <= 15 && lengthPQ(waitingQ) <= 7 && !gameOver)
    {
        printf("SALDO : %d\n\n", saldo);
        if (!IsEmptyList(cookingQ))
        {
            for (int i = FirstIdxList(cookingQ); i != LastIdxList(cookingQ) + 1; i++)
            {
                // pengurangan cookDuration
                if (cookingQ.food[i].cookDuration > 0)
                {
                    cookingQ.food[i].cookDuration--;
                }

                // pengurangan stayDuration
                else if (cookingQ.food[i].cookDuration == 0)
                {
                    InsertAtList(&servingQ, cookingQ.food[i], LastIdxList(servingQ) + 1);
                    DeleteAtList(&cookingQ, i);
                }

                // cookDuration < 0
                else
                {
                    cookingQ.food[i].cookDuration = 0;
                }
            }
        }
        for (int i = FirstIdxList(servingQ); i != LastIdxList(servingQ); i++)
        {
            if (servingQ.food[i].stayDuration == 0)
            {
                PQElType brokenFood;
                brokenFood = GetListChar(servingQ, i);
                DeleteAtList(&servingQ, i);
                printf("Makanan M%d telah rusak\n", brokenFood.foodID);
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
                displayQueuePQ(waitingQ);
                // printf("M%d      | %d              | %d         | %d    \n", waitingQ.buffer[i].foodID, waitingQ.buffer[i].cookDuration, waitingQ.buffer[i].stayDuration, waitingQ.buffer[i].price);
            }
        }

        delay(500);

        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n");
        printf("Makanan | Sisa durasi memasak\n");
        printf("-----------------------------\n");
        displayTime(cookingQ);
        printf("\n");

        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan | Sisa ketahanan makanan\n");
        printf("-----------------------------\n");
        displayStay(servingQ);
        printf("\n");
        delay(500);

        // input command
        printf("Masukkan permintaan ('%s / %s' + ' ' + M {0 - %d}): ", cook, serve, len - 1);
        // scanf("%s %s", command, cookedFood);
        STARTINPUTKATA();
        while (!(IsEqual(takeword(currentWord, 1), "COOK") || IsEqual(takeword(currentWord, 1), "SERVE") || IsEqual(takeword(currentWord, 1), "SKIP")))
        {
            otherCommand();
            printf("Masukkan permintaan ('%s / %s' + ' ' + M {0 - %d}): ", cook, serve, len - 1);
            STARTINPUTKATA();
        }

        // M20 mau diambil 20nya
        int i = 1;
        int id = 0;
        while (takeword(currentWord, 2).TabWord[i] != '\0')
        {
            id = id * 10 + (takeword(currentWord, 2).TabWord[i] - '0');
            i++;
        }

        while (!isMemberPQ(waitingQ, id))
        {
            printf("Makanan tidak ada dalam daftar pesanan\n");
            printf("Masukkan permintaan ('%s / %s' + ' ' + M {0 - %d}): ", cook, serve, len - 1);
            STARTINPUTKATA();
        }
        printf("\n");

        //  validasi input command
        // while (!(compare(command, cook) || compare(command, serve)))
        // {
        //     otherCommand();
        //     printf("Masukkan permintaan ('%s / %s' + ' ' + M {0 - %d}): ", cook, serve, len - 1);
        //     scanf("%s %s", command, cookedFood);
        // }

        // while (!((cookedFood, "M0") || compare(cookedFood, "M1") || compare(cookedFood, "M2") || compare(cookedFood, "M3") || compare(cookedFood, "M4") || compare(cookedFood, "M5") || compare(cookedFood, "M6") || compare(cookedFood, "M7") || compare(cookedFood, "M8") || compare(cookedFood, "M9")))
        // {
        //     otherCommand();
        //     printf("Masukkan permintaan ('%s / %s' + ' ' + M {0 - %d}): ", cook, serve, len - 1);
        //     scanf("%s %s", command, cookedFood);
        // }

        // mengubah cookedFood menjadi int
        // int id = 0;
        // for (int i = 1; cookedFood[i] != '\0'; i++)
        // {
        //     id = id * 10 + (cookedFood[i] - '0');
        // }

        delay(500);
        // COOK
        if (IsEqual(takeword(currentWord, 1), "COOK"))
        {
            InsertLastList(&cookingQ, waitingQ.buffer[id]);
            cookingQ.food[LastIdxList(cookingQ)].cookDuration++;
            printf("Makanan M%d telah dimasukkan ke dalam antrian memasak\n", cookingQ.food[LastIdxList(cookingQ)].foodID);
            foodQueue++;
        }

        // SERVE
        else if (IsEqual(takeword(currentWord, 1), "SERVE"))
        {
            PQElType servableFood;
            PQElType currentFood;

            int i = FirstIdxList(servingQ);
            boolean found = false;

            while (i != LastIdxList(servingQ) + 1 && !found)
            {
                if (servingQ.food[i].foodID == id)
                {
                    currentFood = servingQ.food[i];
                    found = true;
                }
                i = (i + 1) % PQCAPACITY;
            }

            if (currentFood.cookDuration == 0)
            {
                if (currentFood.stayDuration > 0)
                {
                    if (currentFood.foodID == waitingQ.buffer[IDX_HEAD(waitingQ)].foodID)
                    {
                        // dequeueAtIdx(&cookingAndServingQ, &servableFood, i);
                        dequeuePQ(&waitingQ, &servableFood);
                        printf("Makanan M%d telah disajikan\n", servableFood.foodID);
                        saldo += servableFood.price;
                        successfulServe++; // increment successful serve
                    }

                    else
                    {
                        printf("Makanan M%d belum dapat disajikan karena M%d belum disajikan\n", id, waitingQ.buffer[IDX_HEAD(waitingQ)].foodID);
                    }
                }
            }

            else
            {
                printf("Makanan M%d belum siap disajikan\n", id);
            }
        }

        else if (IsEqual(takeword(currentWord, 1), "SKIP"))
        {
            printf("Kamu telah skip ronde kali ini\n", id);
        }

        // displayQueuePQ(cookingAndServingQ);
        printf("\n");

        printf("=============================================================================================\n\n");
        delay(500);
        if (successfulServe != 15 && len < 7)
        {
            enqueuePQ(&waitingQ, createFood(len));
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