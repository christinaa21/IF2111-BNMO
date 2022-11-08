#include <stdio.h>
#include "list.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList()
{
	List L;
	int i;
	L.food[MaxEl];
	for (i = 0; i < MaxEl; i++)
	{
		L.food[i].foodID = Mark;
		L.food[i].cookDuration = Mark;
		L.food[i].stayDuration = Mark;
		L.food[i].price = Mark;
	}
	return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmptyList(List L)
{
	return (L.food[0].foodID == Mark);
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
PQElType GetList(List L, IdxType i)
{
	return (L.food[i]);
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void SetList(List *L, IdxType i, PQElType v)
{
	(*L).food[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthList(List L)
{
	int count = 0;

	while ((L.food[count].foodID != Mark) && (count < MaxEl))
	{
		count++;
	}
	return count;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdxList(List L)
{
	return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdxList(List L)
{
	return (Length(L) - 1);
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidList(List L, IdxType i)
{
	return ((i >= 0) && (i < MaxEl));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEffList(List L, IdxType i)
{
	return ((i >= 0) && (i <= LastIdx(L)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean SearchList(List L, PQElType X)
{
	int i = 0;
	while ((L.food[i].foodID != X.foodID) && (L.food[i].foodID != Mark))
	{
		i++;
	}
	return (L.food[i].foodID == X.foodID);
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirstList(List *L, PQElType X)
{
	InsertAtList(L, X, FirstIdx(*L));
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtList(List *L, PQElType X, IdxType i)
{
	int j;
	for (j = Length(*L); j >= i; j--)
	{
		(*L).food[j] = (*L).food[j - 1];
	}
	(*L).food[i] = X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastList(List *L, PQElType X)
{
	InsertAtList(L, X, LengthList(*L));
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstList(List *L)
{
	DeleteAtList(L, FirstIdxList(*L));
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtList(List *L, IdxType i)
{
	int j;
	for (j = i; j < LengthList(*L) - 1; j++)
	{
		(*L).food[j] = (*L).food[j + 1];
	}
	(*L).food[Length(*L) - 1].foodID = Mark;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastList(List *L)
{
	DeleteAtList(L, LastIdx(*L));
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List ConcatList(List L1, List L2)
{
	List L3 = MakeList();
	int i;
	if (Length(L1) + Length(L2) > MaxEl)
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
		L3.food[Length(L1) + i] = L2.food[i];
		i++;
	}
	return L3;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */