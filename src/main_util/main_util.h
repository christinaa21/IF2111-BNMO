#ifndef __MAIN_UTIL__H__
#define __MAIN_UTIL__H__

#include <stdio.h>
#include "../ADT/arrayOfGame/arrayOfGame.h"
#include "../ADT/mesinkata/mesinkata.h"

// start, load, save, quit, help, other command
// Path: src\main_util\main_util.c

void start();
// I.S. Sembarang
// F.S. menjalankan program dengan melakukan load terhadap konfigurasi

void load(char* savefile, ArrayOfGame *arrGame);
// I.S. Program telah berjalan
// F.S. Menjalankan file yang telah tersimpan sebelumnya dari file eksternal

void save();
// I.S. Program telah berjalan
// F.S. Menyimpan file yang telah dijalankan ke dalam file eksternal

void help();
// I.S. Program telah berjalan
// F.S. Menampilkan bantuan untuk penggunaan program

void quit();
// I.S. Program sedang berjalan
// F.S. Keluar dari program dengan array telah didealokasikan

void otherCommand();
// I.S. Program sedang berjalan
// F.S. Menampilkan pesan bahwa command yang dimasukkan tidak valid
#endif