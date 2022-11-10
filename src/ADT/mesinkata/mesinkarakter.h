/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '\0'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

/* ********** KONSTRUKTOR ********** */
/* Prosedur yang memproses dari mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari FILE.
   I.S : sembarang
   F.S : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void START(char * FILE);

/* Prosedur yang memproses dari mesin siap dioperasikan. Pita disiapkan untuk dibaca.
 * Karakter pertama yang ada pada pita posisinya adalah pada jendela.
 * Pita baca diambil dari stdin.
 * I.S : sembarang
 * F.S : currentChar adalah karakter pertama pada pita
 *        Jika currentChar != MARK maka EOP akan padam (false)
 *        Jika currentChar = MARK maka EOP akan menyala (true) */
void STARTINPUT();

/* Prosedur untuk memajukan pita satu karakter.
 * I.S : Karakter pada jendela = currentChar, currentChar != MARK
 * F.S : currentChar adalah karakter berikutnya dari currentChar yang lama,
 *        currentChar mungkin = MARK
 *        Jika  currentChar = MARK maka EOP akan menyala (true) */
void ADV();

/* ********** SELEKTOR ********** */
/* Fungsi yang mengembalikan nilai currentChar 
   Prekondisi : program telah berjalan */
char GetCC();

/* ********** TEST EOP ********** */
/* Fungsi yang mengirimkan nilai kebenaran jika currentChar adalah EOP
 * Prekondisi : program telah berjalan */
boolean IsEOP();

#endif
