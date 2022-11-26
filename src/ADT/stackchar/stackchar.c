#include <stdio.h>
#include "stackchar.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackchar(Stackchar *S)
{
	Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStackchar */
/* jadi indeksnya antara 0.. MaxElStackchar */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackchar(Stackchar S)
{
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackchar(Stackchar S)
{
	return Top(S) == MaxElStackchar - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackchar(Stackchar *S, infotypeStackchar X)
{
	Top(*S)++;
	InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackchar(Stackchar *S, infotypeStackchar *X)
{
	(*X) = InfoTop(*S);
	Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintStackchar(Stackchar S)
{
	int i;
	if (!IsEmptyStackchar(S))
	{
		for (i = Top(S); i >= 0; i--)
		{
			printf("%d\n", S.T[i]);
		}
	}
	else
	{
		printf("Stack kosong");
	}

	printf("\n");
}
