/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackchart_H
#define stackchart_H

#include "boolean.h"

#define NilStackchar -1
#define MaxElStackchar 100
/* Nil adalah stack dengan elemen kosong . */

typedef char *infotypeStackchar;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  infotypeStackchar T[MaxElStackchar]; /* tabel penyimpan elemen */
  address TOPSTACKCHAR;                /* alamat TOP: elemen puncak */
} Stackchar;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxElStackchar-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopStackchar(S) (S).TOPSTACKCHAR
#define InfoTopStackchar(S) (S).T[(S).TOPSTACKCHAR]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackChar(Stackchar *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStackchar */
/* jadi indeksnya antara 0.. MaxElStackchar */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackChar(Stackchar S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackChar(Stackchar S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackChar(Stackchar *S, infotypeStackchar X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackChar(Stackchar *S, infotypeStackchar *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintStackChar(Stackchar S);
/* I.S. S mungkin kosong */
/* F.S. Jika S tidak kosong, semua elemen S diprint */
/* Jika S kosong, hanya menuliskan "Stack kosong" */

void CopyStackChar (Stackchar sIn, Stackchar * sOut);
    /* Membuat salinan sOut */
    /* I.S. sIn terdefinisi, sOut sembarang */
    /* sOut berisi salinan sIn yang identik */

void InverseStackChar (Stackchar *S);
    /* Membalik isi suatu Stack */
    /* I.S. s terdefinisi */
    /* F.S. Isi s terbalik dari posisi semula */

Stackchar MergeStackChar (Stackchar s1, Stackchar s2);
    /* Menghasilkan sebuah stack yang merupakan hasil penggabungan s1
       dengan s2 dengan s1 berada di posisi yang lebih "bawah". Urutan kedua
       stack harus sama seperti aslinya. */
    /* Stack baru diisi sampai seluruh elemen s1 dan s2 masuk ke dalam stack,
       atau jika stack baru sudah penuh, maka elemen yang dimasukkan adalah
       secukupnya yang dapat ditampung. */

#endif
