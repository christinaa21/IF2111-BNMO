#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "set.h"
#include "boolean.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
{
    (*S).Count = NilSet;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxElSet */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
{
    return (S.Count == NilSet);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S)
{
    return (S.Count == MaxElSet);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxElSet */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotypeSet Elmt)
{
    if (IsEmptySet(*S))
    {
        (*S).Count = 1;
        (*S).Elements[0] = Elmt;
    }
    else
    {
        if (!IsMemberSet(*S, Elmt))
        {
            (*S).Elements[(*S).Count] = Elmt;
            (*S).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, infotypeSet Elmt)
{
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;
    /*ALGORITMA*/
    while ((i < (*S).Count) && (found == false))
    {
        if (IsMemberSet(*S, Elmt))
        {
            found = true;
        }
        i++;
    }

    while ((i < (*S).Count) && (found == true))
    {
        (*S).Elements[i] = (*S).Elements[i + 1];
        i++;
    }

    (*S).Count -= 1;
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotypeSet Elmt)
{
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;

    /*ALGORITMA*/
    while ((i < S.Count) && (found == false))
    {
        if (S.Elements[i] == Elmt)
        {
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

void displaySet(Set S)
{
    for (int i = 0; i < S.Count; i++)
    {
        printf("%d\n", S.Elements[i]);
        printf("\n");
    }
}