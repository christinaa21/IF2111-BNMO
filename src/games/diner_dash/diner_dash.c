// rng, diner dash, and other games

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./diner_dash.h"

// bikin adt queue dinerdash

void RandomNumberGenerator(int n)
{
}
//
// -	Setiap permainan dimulai dengan program sudah menentukan sebuah angka acak X.
// -	Di setiap giliran, pemain diberi kesempatan menebak angka X. Game akan memberi tahu apakah tebakan pemain dibandingkan terhadap X lebih besar atau lebih kecil.
// -	Permainan selesai jika pemain menebak angka X dengan benar.
// -	Skor untuk game ini tergantung dengan seberapa cepat pemain menebak X. Formula skor dibebaskan.
// -	Batasan X dan maksimal giliran dibebaskan.

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
    printf("SALDO : %d", saldo);

    while (foodQueue <= 7 && customer <= 15)
    {

        printf("Daftar Pesanan: ");
        printf("Makanan | Durasi memasak | Ketahanan | Harga");
        printf("--------------------------------------------");
        // print queue

        printf("Daftar Makanan yang sedang dimasak");
        printf("Makanan | Sisa durasi memasak");
        printf("-----------------------------");
        printf("        |                  ");

        printf("Daftar Makanan yang dapat disajikan");
        printf("Makanan | Sisa ketahanan makanan");
        printf("-----------------------------");
        printf("        |                  ");

        // input command
        printf("Masukkan command: ");
        scanf("%s", input);

        //  handle input command

        // baca sampe sebelum spasi

        int i = 0;
        char command[5];
        while (input[i] != " ")
        {
            command[i] = input[i];
            i++;

            if (command != "COOK" || command != "SERVE")
            {
                printf(otherinput());
                printf("Masukkan input: ");
                scanf("%s", input);
            }
        }

        // -	COOK merupakan command yang bertujuan untuk memasak makanan
        if (command == "COOK")
        {
            printf("Berhasil memasak %s", command);
        }

        // -	SERVE merupakan command yang bertujuan untuk menyajikan makanan kepada pelanggan.
        else if (command == "SERVE")
        {
        }
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