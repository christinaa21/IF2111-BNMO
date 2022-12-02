#include <stdio.h>
#include "stackchar.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackChar(Stackchar *S)
{
    TopStackchar(*S) = NilStackchar;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStackchar */
/* jadi indeksnya antara 0.. MaxElStackchar */
/* Ciri stack kosong : TOP bernilai Nil */
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackChar(Stackchar S)
{
    return TopStackchar(S) == NilStackchar;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackChar(Stackchar S)
{
    return TopStackchar(S) == MaxElStackchar - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackChar(Stackchar *S, infotypeStackchar X)
{
    TopStackchar(*S)++;
    InfoTopStackchar(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackChar(Stackchar *S, infotypeStackchar *X)
{
    (*X) = InfoTopStackchar(*S);
    TopStackchar(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen StackTopStackchar yang lama, TOP berkurang 1 */

void PrintStackChar(Stackchar S)
{
    int i;
    if (!IsEmptyStackChar(S))
    {
        for (i = TopStackchar(S); i >= 0; i--)
        {
            printf("%s\n", S.T[i]);
        }
    }
    else
    {
        printf("Stack kosong");
    }

    printf("\n");
}

void CopyStackChar(Stackchar sIn, Stackchar *sOut)
{
    /* Membuat salinan sOut */
    /* I.S. sIn terdefinisi, sOut sembarang */
    /* sOut berisi salinan sIn yang identik */
    Stackchar temp;
    infotypeStackchar x;

    CreateEmptyStackChar(&temp);
    while (!IsEmptyStackChar(sIn))
    {
        PopStackChar(&sIn, &x);
        PushStackChar(&temp, x);
    }
    while (!IsEmptyStackChar(temp))
    {
        PopStackChar(&temp, &x);
        PushStackChar(&sIn, x);
        PushStackChar(sOut, x);
    }
}

void InverseStackChar(Stackchar *S)
{
    /* Membalik isi suatu Stack */
    /* I.S. s terdefinisi */
    /* F.S. Isi s terbalik dari posisi semula */
    Stackchar temp;
    infotypeStackchar x;
    CreateEmptyStackChar(&temp);
    CopyStackChar((*S), &temp);
    while (!IsEmptyStackChar(*S))
    {
        PopStackChar(S, &x);
    }
    while (!IsEmptyStackChar(temp))
    {
        PopStackChar(&temp, &x);
        PushStackChar(S, x);
    }
}

Stackchar MergeStackChar(Stackchar s1, Stackchar s2)
{
    /* Menghasilkan sebuah stack yang merupakan hasil penggabungan s1
       dengan s2 dengan s1 berada di posisi yang lebih "bawah". Urutan kedua
       stack harus sama seperti aslinya. */
    /* Stack baru diisi sampai seluruh elemen s1 dan s2 masuk ke dalam stack,
       atau jika stack baru sudah penuh, maka elemen yang dimasukkan adalah
       secukupnya yang dapat ditampung. */
    int i;
    Stackchar s;
    infotypeStackchar x;
    CreateEmptyStackChar(&s);
    CopyStackChar(s1, &s);
    InverseStackChar(&s2);
    while (!IsFullStackChar(s))
    {
        PopStackChar(&s2, &x);
        PushStackChar(&s, x);
    }
    return s;
}