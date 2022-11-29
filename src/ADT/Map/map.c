#include <stdio.h>
#include <stdlib.h>
#include "map.h"

/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : CountMap bernilai Nil */
void CreateEmptyMap(Map *M)
{
    (*M).CountMap = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : CountMap bernilai Nil */
boolean IsEmptyMap(Map M)
{
    return ((M).CountMap == NilMap);
}

/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : CountMap bernilai MaxElMap */
boolean IsFullMap(Map M)
{
    return ((M).CountMap == MaxElMap);
}

/* ********** Operator Dasar Map ********* */
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
valuetype ValueMap(Map M, keytype k)
{
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;
    /*ALGORITMA*/
    while (i < M.CountMap && found == false)
    {
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        else
        {
            i += 1;
        }
    }
    if (found)
    {
        return (M.Elements[i].Value);
    }
    else
    {
        return Undefined;
    }
}

/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
void InsertMap(Map *M, keytype k, valuetype v)
{
    if (IsEmptyMap(*M))
    {
        (*M).CountMap = 1;
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
    }
    else
    {
        if (!IsMemberMap(*M, k))
        {
            (*M).Elements[(*M).CountMap].Key = k;
            (*M).Elements[(*M).CountMap].Value = v;
            (*M).CountMap++;
        }
    }
}

/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
void DeleteMap(Map *M, keytype k)
{
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;

    /*ALGORITMA*/
    if (IsMemberMap(*M, k))
    {
        while (i < (*M).CountMap && found == false)
        {
            if ((*M).Elements[i].Key == k)
            {
                found = true;
            }
            else
            {
                i += 1;
            }
        }
        int j;
        for (j = i; j < (*M).CountMap; j++)
        {
            (*M).Elements[j] = (*M).Elements[j + 1];
        }
        (*M).CountMap -= 1;
    }
}

/* Mengembalikan true jika k adalah member dari M */
boolean IsMemberMap(Map M, keytype k)
{
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;

    /*ALGORITMA*/
    // capsLock(k);
    while ((i < M.CountMap) && (found == false))
    {
        // capsLock(M.Elements[i].Key);
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

/* Prosedur untuk menampilkan semua daftar map untuk scoreboard
 I.S. : scoreboard terdefinisi
 F.S> : semua map berhasil di print*/
void displayMap(Map M)
{
    // printf("**** SCOREBOARD ****\n");
    // printf("| NAMA       | SKOR      |\n");
    // printf("|------------------------|\n");
    //     if (IsEmptyMap(M)){
    //         printf("-----SCOREBOARD KOSONG-----\n");
    //     } else {
    for (int i = 0; i < M.CountMap; i++)
    {
        printf("| %s\t\t\t| %d\t\t\t|\n", M.Elements[i].Key, M.Elements[i].Value);
        //}
    }
}