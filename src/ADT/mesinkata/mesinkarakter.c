#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "boolean.h"

/*KAMUS*/
char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

/* ********** KONSTRUKTOR ********** */
/* Prosedur yang memproses dari mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari FILE.
   I.S : sembarang
   F.S : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
void START(char *FILE)
{
   /*KAMUS LOKAL*/

   /*ALGORITMA*/
   pita = fopen(FILE, "r");
   ADV();
}

/* Prosedur yang memproses dari mesin siap dioperasikan. Pita disiapkan untuk dibaca.
 * Karakter pertama yang ada pada pita posisinya adalah pada jendela.
 * Pita baca diambil dari stdin.
 * I.S : sembarang
 * F.S : currentChar adalah karakter pertama pada pita
 *        Jika currentChar != MARK maka EOP akan padam (false)
 *        Jika currentChar = MARK maka EOP akan menyala (true) */
void STARTINPUT()
{
   /*KAMUS LOKAL*/

   /*ALGORITMA*/
   pita = stdin;
   ADV();
}

/* Prosedur untuk memajukan pita satu karakter.
 * I.S : Karakter pada jendela = currentChar, currentChar != MARK
 * F.S : currentChar adalah karakter berikutnya dari currentChar yang lama,
 *        currentChar mungkin = MARK
 *        Jika  currentChar = MARK maka EOP akan menyala (true) */
void ADV()
{
   /*KAMUS LOKAL*/

   /*ALGORITMA*/
   retval = fscanf(pita, "%c", &currentChar);
   EOP = (currentChar == MARK || feof(pita));
   if (EOP)
   {
      fclose(pita);
   }
}

/* ********** SELEKTOR ********** */
/* Fungsi yang mengembalikan nilai currentChar
   Prekondisi : program telah berjalan */
char GetCC()
{
   /*KAMUS LOKAL*/

   /*ALGORITMA*/
   return currentChar;
}

/* ********** TEST EOP ********** */
/* Fungsi yang mengirimkan nilai kebenaran jika currentChar adalah EOP
 * Prekondisi : program telah berjalan */
boolean IsEOP()
{
   /*KAMUS LOKAL*/

   /*ALGORITMA*/
   return (currentChar == MARK || feof(pita));
}
