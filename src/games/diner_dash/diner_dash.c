// rng, diner dash, and other games

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./diner_dash.h"

boolean compare(char str1[], char str2[])
{
    boolean found = false, i = 0;                        // integer variables declaration
    while (str1[i] != '\0' && str2[i] != '\0' && !found) // while loop
    {
        if (str1[i] != str2[i])
        {
            found = true;
        }
        i++;
    }

    return !found;
}
void DinerDash()
{
    // Kamus

    // Algoritma

    // bikin adt queue baru, adt meal (id, durasi masak, Ketahanan, price)

    // -	Terdapat 2 command yang dapat dilakukan pada game, yaitu COOK dan SERVE

    char input[100];
    int customer = 0;
    int foodQueue = 0;
    int saldo = 0;
    printf("Selamat datang di Diner Dash");

    Queue q;

    while (foodQueue <= 7 && customer <= 15)
    {
        printf("SALDO : %d", saldo);

        printf("Daftar Pesanan: ");
        printf("Makanan | Durasi memasak | Ketahanan | Harga");
        printf("--------------------------------------------");
        // print queue

        printf("Daftar Makanan yang sedang dimasak");
        printf("Makanan | Sisa durasi memasak");
        printf("-----------------------------");
        printf("%s      | %d                 ", HEAD(q).ID, HEAD(q).cookDuration);

        printf("Daftar Makanan yang dapat disajikan");
        printf("Makanan | Sisa ketahanan makanan");
        printf("-----------------------------");
        printf("%s      | %d                ", HEAD(q).ID, HEAD(q).stayDuration);

        // input command
        printf("Masukkan command: ");
        scanf("%s", input);

        // baca sampe sebelum spasi

        int i = 0;
        char command[5];
        while (input[i] != ' ')
        {
            command[i] = input[i];
            i++;
        }

        i++;
        char cookedFood[5];
        while (input[i] != '\0')
        {
            cookedFood[i] = input[i];
        }

        //  handle input command
        while (!compare(command, "COOK") || !compare(command, "SERVE") || !compare(cookedFood, "M0") || !compare(cookedFood, "M1") || !compare(cookedFood, "M2") || !compare(cookedFood, "M3") || !compare(cookedFood, "M4") || !compare(cookedFood, "M5") || !compare(cookedFood, "M6") || !compare(cookedFood, "M7") || !compare(cookedFood, "M8") || !compare(cookedFood, "M9") || !compare(cookedFood, "M10") || !compare(cookedFood, "M11") || !compare(cookedFood, "M12") || !compare(cookedFood, "M13") || !compare(cookedFood, "M14"))
        {
            otherCommand();
            printf("Masukkan command: ");
            scanf("%s", input);

            // baca sampe sebelum spasi

            int i = 0;
            char command[5];
            while (input[i] != ' ')
            {
                command[i] = input[i];
                i++;
            }

            i++;
            char cookedFood[5];
            while (input[i] != '\0')
            {
                cookedFood[i] = input[i];
            }
        }

        if (compare(command, "COOK"))
        {
            printf("Makanan %s telah dimasukkan ke dalam antrian", cookedFood);

            // masukin cook duration ke array
            // kurnag-kurangin dari array,
            // tampilin ke daftar masakan yang sedang dimasak
            foodQueue++;

            // bikin makanan baru
            // masukin ke queue
            // print queue
        }

        else if (compare(command, "SERVE"))
        {
            if (compare(cookedFood, HEAD(q).ID))
            {
                if (HEAD(q).cookDuration == 0)
                {
                    printf("Makanan %s telah selesai dimasak", HEAD(q).ID);
                }
            }

            else
            {
                printf("Makanan %s tidak dapat disajikan karena %s belum selesai", cookedFood, HEAD(q).ID);
            }
            // print queue
            // print makanan yang sedang dimasak
            // print makanan yang dapat disajikan
            // print saldo
        }

        printf("=============================================================================================");

        // -	COOK merupakan command yang bertujuan untuk memasak makanan
        // input command
    }
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