#ifndef __MAIN_UTIL__H__
#define __MAIN_UTIL__H__

#include <stdio.h>
#include "../ADT/array/arraydin.h"

// start, load, save, quit, help
// Path: src\main_util\main_util.c

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

void quit(ArrayDin *arr);
// I.S. Program sedang berjalan
// F.S. Keluar dari program dengan array telah didealokasikan
#endif