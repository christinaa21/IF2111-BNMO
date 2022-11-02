#include "../ADT/queue/queue.h"
#include "../ADT/array/arraydin.h"
#include "./main_util.h"
#include <stdlib.h>
#include <stdio.h>
// start, load, save, quit, help

void start();
// I.S. Sembarang
// F.S. menjalankan program dengan melakukan load terhadap konfigurasi

void load();
// I.S. Program telah berjalan
// F.S. Menjalankan file yang telah tersimpan sebelumnya dari file eksternal

void save();
// I.S. Program telah berjalan
// F.S. Menyimpan file yang telah dijalankan ke dalam file eksternal

void help();
// I.S. Program telah berjalan
// F.S. Menampilkan bantuan untuk penggunaan program

void quit(ArrayDin *arr)
{
    // DeallocateArrayDin(arr);
    printf("Game has ended\n");
    exit(0);
}
// I.S. Program sedang berjalan
// F.S. Keluar dari program dengan array telah didealokasikan

void otherCommand()
{
    printf("Command yang diberikan tidak sesuai yang diinginkan\n");
}
// I.S. Program sedang berjalan
// F.S. Menampilkan pesan bahwa command yang dimasukkan tidak valid