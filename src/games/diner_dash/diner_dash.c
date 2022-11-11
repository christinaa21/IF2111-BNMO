#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "./diner_dash.h"

/*Fungsi yang mengembalikan true jika str1 sama dengan str2*/

/*Fungsi untuk membuat makanan*/
PQElType createFood(int id)
{
    /*KAMUS LOKAL*/
    PQElType food;
    srand(time(NULL));
    /*ALGORITMA*/
    (food).foodID = id;
    (food).cookDuration = abs(rand() % 5 + 1);
    while (food.cookDuration == 0)
    {
        food.cookDuration = abs(rand() % 5 + 1);
    }
    (food).stayDuration = abs((rand() * 5 + rand() * 2) % 5 + 1);
    while (food.stayDuration == 0)
    {
        food.stayDuration = abs((rand() * 5 + rand() * 2) % 5 + 1);
    }
    (food).price = abs((rand() % 4 + 1) * 10000 + rand() % 9 * 1000 + (rand() % 9) * 100);
    while (food.price == 0)
    {
        food.price = abs((rand() % 4 + 1) * 10000 + rand() % 9 * 1000 + (rand() % 9) * 100);
    }
    return food;
}

/* Prosedur transversal hingga mencapai waktu yang dibutuhkan
 * I.S : terdefinisi
 * F.S : waktu telah mencapai yang dibutuhkan kemudian looping terselesaikan */
void delay(int number_of_milliseconds)
{
    // Converting time into milli_seconds
    int milli_seconds = number_of_milliseconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

/*** Penjelasan Permainan ***\
 * -	Terdapat 2 command yang dapat dilakukan pada game, yaitu COOK dan SERVE
 * -	COOK merupakan command yang bertujuan untuk memasak makanan
 * -	SERVE merupakan command yang bertujuan untuk menyajikan makanan kepada pelanggan.
 * -	Permainan akan dimulai dengan 3 pelanggan. Setiap pelanggan hanya dapat memesan satu makanan. Untuk setiap makanan, terdapat informasi tentang ID makanan yang dihasilkan secara increment (M01, M02, M03, dst), durasi memasak, harga makanan, serta ketahanan makanan. Semua informasi tersebut akan didapatkan secara random dengan menggunakan random number generator. Durasi dan ketahanan makanan akan berkisar diantara 1-5. Sedangkan, harga makanan akan berkisar diantara 10000 - 50000.
 * -	Kapasitas dari pemain adalah memasak 5 makanan dalam waktu yang sama. Pelanggan yang dilayani adalah pelanggan yang duluan memasuki antrian.
 * -	Permainan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan.
 * -	Pada setiap putaran, akan terdapat 1 pelanggan baru.
 * -	Pada setiap putaran, seluruh durasi dari makanan yang sedang dimasak akan berkurang 1. Ketika durasi makanan mencapai 0, maka makanan sudah dapat di SERVE.
 * -	Ketika makanan sudah di SERVE, maka makanan dapat diantar kepada pelanggan dan pelanggan dapat meninggalkan antrian. Setelah pelanggan meninggalkan antrian, maka pemain akan menerima uang
 * -	SERVE hanya dapat digunakan untuk pesanan yang berada di paling depan.
 * -	Skor akhir dari pemain adalah total uang yang diterima oleh pemain. */
void DinerDash()
{
    /*KAMUS LOKAL*/
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

    /*ALGORTIMA*/
    printf("Selamat datang di Diner Dash\n");

    printf("\n");
    if (isEmptyPQ(waitingQ) && firstRound)
    {
        int i = IDX_HEAD(waitingQ) + 1;
        while (lengthPQ(waitingQ) < 3)
        {
            enqueuePQ(&waitingQ, createFood(i));
            sleep(1);
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
            for (int i = FirstIdxList(cookingQ); i < LastIdxList(cookingQ) + 1; i++)
            {
                // pengurangan cookDuration
                if (cookingQ.food[i].cookDuration > 0)
                {
                    cookingQ.food[i].cookDuration--;
                }
            }
            int i = FirstIdxList(cookingQ);
            while (i != LastIdxList(cookingQ) + 1)
            {
                if (cookingQ.food[i].cookDuration == 0)
                {
                    InsertAtList(&servingQ, cookingQ.food[i], LastIdxList(servingQ) + 1);
                    servingQ.food[LastIdxList(servingQ)].stayDuration++;
                    DeleteAtList(&cookingQ, i);
                    i--;
                }
                i++;
            }
        }
        if (!IsEmptyList(servingQ))
        {
            for (int i = FirstIdxList(servingQ); i < LengthList(servingQ); i++)
            {
                if (servingQ.food[i].stayDuration > 0)
                {
                    servingQ.food[i].stayDuration--;
                }
            }
            int i = FirstIdxList(servingQ);
            while (i != LastIdxList(servingQ) + 1)
            {
                if (servingQ.food[i].stayDuration == 0)
                {
                    PQElType brokenFood;
                    brokenFood = GetListChar(servingQ, i);
                    DeleteAtList(&servingQ, i);
                    printf("Makanan M%d telah rusak\n", brokenFood.foodID);
                    i--;
                }
                i++;
            }
        }

        printf("Daftar pesanan: \n");
        printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
        printf("--------------------------------------------\n");

        int len = lengthPQ(waitingQ);

        if (len > 0)
        {
            displayQueuePQ(waitingQ);
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
        printf("Masukkan permintaan ('%s / %s' + ' ' + M {indeks yang ada pada daftar pesanan}) / 'SKIP': ", cook, serve);
        STARTINPUTKATA();
        while (!(IsEqual(takeword(currentWord, 1), "COOK") || IsEqual(takeword(currentWord, 1), "SERVE") || IsEqual(takeword(currentWord, 1), "SKIP")))
        {
            otherCommand();
            printf("Masukkan permintaan ('%s / %s' + ' ' + M {indeks yang ada pada daftar pesanan}): ", cook, serve);

            STARTINPUTKATA();
        }

        int id = 0;
        if (currentWord.Length > 4)
        {
            int i = 1;

            while (WordToString(takeword(currentWord, 2))[i] != '\0')
            {
                id = id * 10 + (WordToString(takeword(currentWord, 2))[i] - '0');
                i++;
            }
            // printf("id : %d\n", id);

            while (!isMemberPQ(waitingQ, id))
            {
                printf("Makanan tidak ada dalam daftar pesanan\n");
                printf("Masukkan permintaan ('%s / %s' + ' ' + M {indeks yang ada pada daftar pesanan}): ", cook, serve);
                STARTINPUTKATA();

                i = 1;
                id = 0;
                while (WordToString(takeword(currentWord, 2))[i] != '\0')
                {
                    id = id * 10 + (WordToString(takeword(currentWord, 2))[i] - '0');
                    i++;
                }
                // printf("id : %d\n", id);
            }
            printf("\n");
        }

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
                        DeleteAtList(&servingQ, minList(servingQ));
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
            printf("Kamu telah skip ronde kali ini\n");
        }

        printf("\n");

        printf("=============================================================================================\n\n");
        delay(500);
        if (successfulServe != 15 && lengthPQ(waitingQ) <= 7)
        {
            enqueuePQ(&waitingQ, createFood(IDX_TAIL(waitingQ) + 1));
        }

        if (successfulServe == 15 || lengthPQ(waitingQ) == 8)
        {
            gameOver = true;
        }
    }

    printf("Berikut hasil akhir daftar pesanan anda:\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    displayQueuePQ(waitingQ);

    printf("Congratulation!\nYou've served %d food\n", successfulServe);
    printf("Game Over \n");
}
