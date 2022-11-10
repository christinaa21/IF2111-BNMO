/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTList1
#define ADTList1

#include "boolean.h"
#include "../prioQueue/prioqueue.h"

/* Kamus Umum */
#define MaxEl 100
#define Mark -9999	  /* Nilai tak terdefinisi */
#define InvalidIdx -1 /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int

typedef struct
{
	PQElType food[MaxEl]; /* Memori tempat penyimpanan elemen (container) */
} List;

#define List(i) L.food(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */


/* ********** KONSTRUKTOR ********** */
/* Fungsi untuk membuat list L kosong dengan kapasitas MaxEL */ 
List MakeList();
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* Fungsi yang true jika list L kosong, mengirimkan false jika tidak 
 * prekonsisi : list terdefinisi
 */ 
boolean IsEmptyList(List L);

/* ********** SELEKTOR ********** */
/* Fungsi yang mengirim elemen list yang ke-i 
 * Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
PQElType GetListChar(List L, IdxType i);

/* Prosedur mengubah nilai list dan elemen list *** */
/* I.S : T terdefinisi, sembarang */
/* F.S : Elemen T yang ke-i bernilai v */
void SetListChar(List *L, IdxType i, PQElType v);

/* Fungsi yang mengirimkan banyaknya elemen efektif list 
 * Mengirimkan nol jika list kosong */
int LengthList(List L);

/* Fungsi yang mengirimkan indeks elemen pertama 
 * Prekondisi : list L tidak kosong */
IdxType FirstIdxList(List L);

/* Fungsi yang mengirimkan indeks elemen terakhir 
 * Prekondisi : list L tidak kosong */
IdxType LastIdxList(List L);

/* ********** TEST INDEKS ********** */
/* Fungsi yang mengirimkan true jika i adalah indeks yang valid utk ukuran list 
 * yaitu antara indeks yang terdefinisi untuk container
 * Prekondisi : i sembarang */
boolean IsIdxValidList(List L, IdxType i);

/* Fungsi yang mengirimkan true jika i adalah indeks yang terdefinisi utk list 
 * yaitu antara FirstIdx(L)..LastIdx(L) 
 * Prekondisi : i sembarang*/
boolean IsIdxEffList(List L, IdxType i);

/* ********** OPERASI OPERASI ********** */
/* Fungsi yang mengirmkan true jika terdapat elemen X di dalam list 
 * yaitu antara FirstIdx(L)..LastIdx(L) 
 * Prekondisi : X sembarang */
boolean SearchList(List L, PQElType X);

/* Prosedur untuk memasukan elemen ke bagian pertama list. 
 * I.S : L terdefinisi, mungkin kosong.
 * F.S : v menjadi elemen pertama L. */
void InsertFirstList(List *L, PQElType X);

/* Prosedur untuk memasukan elemen ke indeks ke-i. 
 * I.S : L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. 
 * F.S : v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertAtList(List *L, PQElType X, IdxType i);

/* Prosedur untuk memasukan elemen ke bagian akhir list. 
 * I.S. L terdefinisi, mungkin kosong. 
 * F.S. v menjadi elemen terakhir L. */
void InsertLastList(List *L, PQElType X);

/* Prosedur untuk menghapus elemen pertama list.
 * I.S : L terdefinisi, tidak kosong. 
 * F.S : F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteFirstList(List *L);

/* Prosedur untuk menghapus elemen ke-i di list.
 * I.S : L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. 
 * F.S : Elemen L pada indeks ke-i dihapus dari L. */
void DeleteAtList(List *L, IdxType i);

/* Prosedur untuk menghapus elemen terakhir di list.
 * I.S : L terdefinisi, tidak kosong. 
 * F.S : F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void DeleteLastList(List *L);

/* Fungsi yang mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
/* Prekondisi : L1 dan L2 tidak kosong */
List ConcatList(List L1, List L2);

#endif