#include <stdio.h>
#include "list.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Fungsi untuk membuat list L kosong dengan kapasitas MaxEL */ 
List MakeList()
{
	/*KAMUS LOKAL*/
	List L;
	int i;
	L.food[MaxEl];
	/*ALGORITMA*/
	for (i = 0; i < MaxEl; i++)
	{
		L.food[i].foodID = Mark;
		L.food[i].cookDuration = Mark;
		L.food[i].stayDuration = Mark;
		L.food[i].price = Mark;
	}
	return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* Fungsi yang true jika list L kosong, mengirimkan false jika tidak 
 * prekonsisi : list terdefinisi
 */ 
boolean IsEmptyList(List L)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (L.food[0].foodID == Mark);
}

/* ********** SELEKTOR ********** */
/* Fungsi yang mengirim elemen list yang ke-i 
 * Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
PQElType GetListChar(List L, IdxType i)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (L.food[i]);
}

/* Prosedur mengubah nilai list dan elemen list *** */
/* I.S : T terdefinisi, sembarang */
/* F.S : Elemen T yang ke-i bernilai v */
void SetListChar(List *L, IdxType i, PQElType v)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	(*L).food[i] = v;
}

/* Fungsi yang mengirimkan banyaknya elemen efektif list 
 * Mengirimkan nol jika list kosong */
int LengthList(List L)
{
	/*KAMUS LOKAL*/
	int count = 0;
	/*ALGORITMA*/
	while ((L.food[count].foodID != Mark) && (count < MaxEl))
	{
		count++;
	}
	return count;
}

/* Fungsi yang mengirimkan indeks elemen pertama 
 * Prekondisi : list L tidak kosong */
IdxType FirstIdxList(List L)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return 0;
}

/* Fungsi yang mengirimkan indeks elemen terakhir 
 * Prekondisi : list L tidak kosong */
IdxType LastIdxList(List L)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (LengthList(L) - 1);
}


/* ********** TEST INDEKS ********** */
/* Fungsi yang mengirimkan true jika i adalah indeks yang valid utk ukuran list 
 * yaitu antara indeks yang terdefinisi untuk container
 * Prekondisi : i sembarang */
boolean IsIdxValidList(List L, IdxType i)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((i >= 0) && (i < MaxEl));
}

/* Fungsi yang mengirimkan true jika i adalah indeks yang terdefinisi utk list 
 * yaitu antara FirstIdx(L)..LastIdx(L) 
 * Prekondisi : i sembarang*/
boolean IsIdxEffList(List L, IdxType i)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((i >= 0) && (i <= LastIdxList(L)));
}

/* ********** OPERASI OPERASI ********** */
/* Fungsi yang mengirmkan true jika terdapat elemen X di dalam list 
 * yaitu antara FirstIdx(L)..LastIdx(L) 
 * Prekondisi : X sembarang */
boolean SearchList(List L, PQElType X)
{
	/*KAMUS LOKAL*/
	int i = 0;
	/*ALGORITMA*/
	while ((L.food[i].foodID != X.foodID) && (L.food[i].foodID != Mark))
	{
		i++;
	}
	return (L.food[i].foodID == X.foodID);
}

/* Prosedur untuk memasukan elemen ke bagian pertama list. 
 * I.S : L terdefinisi, mungkin kosong.
 * F.S : v menjadi elemen pertama L. */
void InsertFirstList(List *L, PQElType X)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	InsertAtList(L, X, FirstIdxList(*L));
}

/* Prosedur untuk memasukan elemen ke indeks ke-i. 
 * I.S : L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. 
 * F.S : v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertAtList(List *L, PQElType X, IdxType i)
{
	/*KAMUS LOKAL*/
	int j;
	/*ALGORTIMA*/
	for (j = LengthList(*L); j >= i; j--)
	{
		(*L).food[j] = (*L).food[j - 1];
	}
	(*L).food[i] = X;
}

/* Prosedur untuk memasukan elemen ke bagian akhir list. 
 * I.S. L terdefinisi, mungkin kosong. 
 * F.S. v menjadi elemen terakhir L. */
void InsertLastList(List *L, PQElType X)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	InsertAtList(L, X, LengthList(*L));
}

/* Prosedur untuk menghapus elemen pertama list.
 * I.S : L terdefinisi, tidak kosong. 
 * F.S : F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteFirstList(List *L)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	DeleteAtList(L, FirstIdxList(*L));
}

/* Prosedur untuk menghapus elemen ke-i di list.
 * I.S : L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. 
 * F.S : Elemen L pada indeks ke-i dihapus dari L. */
void DeleteAtList(List *L, IdxType i)
{
	/*KAMUS LOKAL*/
	int j;
	/*ALGORITMA*/
	for (j = i; j < LengthList(*L) - 1; j++)
	{
		(*L).food[j] = (*L).food[j + 1];
	}
	(*L).food[LengthList(*L) - 1].foodID = Mark;
}

/* Prosedur untuk menghapus elemen terakhir di list.
 * I.S : L terdefinisi, tidak kosong. 
 * F.S : F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void DeleteLastList(List *L)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	DeleteAtList(L, LastIdxList(*L));
}

/* Fungsi yang mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
/* Prekondisi : L1 dan L2 tidak kosong */
List ConcatList(List L1, List L2)
{
	/*KAMUS LOKAL*/
	List L3 = MakeList();
	int i;
	/*ALGORITMA*/
	if (LengthList(L1) + LengthList(L2) > MaxEl)
	{
		L3.food[MaxEl + MaxEl];
		for (i = MaxEl; i <= MaxEl * 2; i++)
		{
			L3.food[i].foodID = Mark;
		}
	}
	i = 0;
	while (L1.food[i].foodID != Mark)
	{
		L3.food[i] = L1.food[i];
		i++;
	}
	i = 0;
	while (L2.food[i].foodID != Mark)
	{
		L3.food[LengthList(L1) + i] = L2.food[i];
		i++;
	}
	return L3;
}
