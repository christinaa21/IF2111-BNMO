#ifndef __MAIN_UTIL__H__
#define __MAIN_UTIL__H__

#include <stdio.h>
#include "../ADT/arrayOfGame/arrayOfGame.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/Map/listMap.h"
#include "../ADT/stackchar/stackchar.h"
#include "../ADT/Map/map.h"

/* Prosedur untuk menjalankan program 
 * I.S : Sembarang.
 * F.S : menjalankan program dengan melakukan load terhadap konfigurasi.
*/
void start();

/* Prosedur untuk menjalankan file yang tersimpan dari history program 
 * I.S. Program telah berjalan.
 * F.S. Menjalankan file yang telah tersimpan sebelumnya dari file eksternal.
*/
void load(char* savefile, ArrayOfGame *arrGame, ArrayOfGame *hist);

/* Prosedur untuk menyimpan file program yang telah dijalankan 
 * I.S : Program telah berjalan.
 * F.S : Menyimpan file yang telah dijalankan ke dalam file eksternal
*/
void save(char *savefile, ArrayOfGame arrGame, Stackchar hist, ListMap L);

/* Prosedur untuk menampilkan command yang bisa dimasukan user 
 * I.S : Program telah berjalan
 * F.S : Menampilkan bantuan untuk penggunaan program
*/
void help();

/* Prosedur untuk berhenti dari program 
 * I.S : Program sedang berjalan
 * F.S : Keluar dari program dengan array telah didealokasikan
*/
void quit(ArrayOfGame arrGame, Stackchar hist, ListMap L);

/* Prosedur untuk menampilkan pesan kesalahan input user 
 * I.S : Program sedang berjalan
 * F.S : Menampilkan pesan bahwa command yang dimasukkan tidak valid
*/
void otherCommand();
#endif