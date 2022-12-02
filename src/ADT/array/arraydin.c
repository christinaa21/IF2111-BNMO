#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Proses Pembentukan ArrayDin kosong dengan ukuran InitialSize.
 */
ArrayDin MakeArrayDin()
{
	/*KAMUS LOKAL*/
	ArrayDin array;
	/*ALGORITMA*/
	(array).A = (ElTypeArrayDin *)malloc(InitialSize * sizeof(ElTypeArrayDin));
	(array).Capacity = InitialSize;
	(array).Neff = 0;
	return array;
}

/* ********** DESTRUKTOR ********** */
/* I.S. ArrayDin terdefinisi.
 * F.S. array->A terdealokasi.
 */
void DeallocateArrayDin(ArrayDin *array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	free((*array).A);
	(*array).Capacity = 0;
	(*array).Neff = 0;
}

/* ********** TEST KOSONG/PENUH ********** */
/* Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi.
 */
boolean IsEmptyArrayDin(ArrayDin array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((array).Neff == 0);
}

/* ********** SELEKTOR ********** */
/* Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi.
 */
int LengthArrayDin(ArrayDin array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (array).Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayDin GetArrayDin(ArrayDin array, IdxTypeArrayDin i)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((array).A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi.
 */
int GetCapacity(ArrayDin array)
{
	/*KAMUS LOKAL*/

	/*ALGORTIMA*/
	return ((array).Capacity);
}

/**
 * Fungsi untuk mengeset x pada elemen array dengan indeks ke-i.
 * Prekondisi: array, i, dan x terdefinisi.
 */
void SetArrayDin(ArrayDin *array, IdxTypeArrayDin i, ElTypeArrayDin x)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	(*array).A[i] = x;
}

/* ********** OPERASI-OPERASI ********** */
/* Fungsi untuk menambahkan elemen baru di index ke-i.
 * I.S : array terdefinisi, i di antara 0..Length(array).
 * F.S : sebuah elemen berhasil ditambahkan pada indeks ke-1.
 */
void InsertAt(ArrayDin *array, ElTypeArrayDin el, IdxTypeArrayDin i)
{
	/*KAMUS LOKAL*/
	// int length = Length(*array);
	// int capacity = GetCapacity(*array);
	int j;
	/*ALGORITMA*/
	if ((*array).Neff == (*array).Capacity)
	{
		(*array).A = (ElTypeArrayDin *)realloc((*array).A, (InitialSize * 2) * sizeof(ElTypeArrayDin));
		(*array).Capacity = InitialSize * 2;
	}
	for (j = (*array).Neff - 1; j >= i; j--)
	{
		(*array).A[j + 1] = (*array).A[j];
	}
	(*array).A[i] = el;
	(*array).Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * I.S : array terdefinisi.
 * F.S : elemen baru berhasil ditambahkan di akhir array.
 */
void InsertLast(ArrayDin *array, ElTypeArrayDin el)
{
	/*KAMUS LOKAL*/
	int j;
	/*ALGORITMA*/
	if ((*array).Neff == (*array).Capacity)
	{
		(*array).A = (ElTypeArrayDin *)realloc((*array).A, (InitialSize * 2) * sizeof(ElTypeArrayDin));
		(*array).Capacity = InitialSize * 2;
	}
	(*array).A[(*array).Neff] = el;
	(*array).Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * I.S : array terdefinisi.
 * F.S : elemen baru berhasil ditambahkan di awal array.
 */
void InsertFirst(ArrayDin *array, ElTypeArrayDin el)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * I.S : array terdefinisi, i di antara 0..Length(array).
 * F.S : elemen pada indeks ke-i berhasil dihapuskan dari array.
 */
void DeleteAt(ArrayDin *array, IdxTypeArrayDin i)
{
	/*KAMUS LOKAL*/
	int j;
	/*ALGORITMA*/
	int length = LengthArrayDin(*array);
	for (j = i; j < length - 1; j++)
	{
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * I.S : array tidak kosong dan terdefinisi.
 * F.S : elemen terakhir pada array berhasil dihapuskan.
 */
void DeleteLast(ArrayDin *array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	int nums = LengthArrayDin(*array);
	DeleteAt(array, nums);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * I.S : array tidak kosong dan array terdefinisi.
 * F.S : elemen pertama pada array berhasil dihapuskan.
 */
void DeleteFirst(ArrayDin *array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Proses 	: Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * 			  dan diakhiri newline.
 * I.S 		: array terdefinisi.
 * F.S 		: array tertuliskan dilayar.
 */
void PrintArrayDin(ArrayDin array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	int i;
	if ((array).Neff == 0)
	{
		printf("[]\n");
	}
	else
	{
		for (i = 0; i < (array).Neff; i++)
		{
			if (i == (array).Neff - 1)
			{
				printf("%s\n", (array).A[i]);
			}
			else
			{
				printf("%s", (array).A[i]);
			}
		}
	}
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * I.S : array terdefinisi.
 * F.S : array berhasil di-reverse.
 */
void ReverseArrayDin(ArrayDin *array)
{
	/*KAMUS LOKAL*/
	int i;
	/*ALGORITMA*/
	int length = LengthArrayDin(*array);
	for (i = 0; i < length / 2; i++)
	{
		ElTypeArrayDin temp = (*array).A[i];
		(*array).A[i] = (*array).A[length - i - 1];
		(*array).A[length - i - 1] = temp;
	}
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi.
 */
ArrayDin CopyArrayDin(ArrayDin array)
{
	/*KAMUS LOKAL*/
	ArrayDin newArr = MakeArrayDin();
	int i;
	/*ALGORITMA*/
	for (i = 0; i < array.Neff; i++)
	{
		InsertLast(&newArr, array.A[i]);
	}
	return newArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Proses 		: Index pertama yang ditemukan akan dikembalikan.
 * 				  Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi	: array terdefinisi.
 */
IdxTypeArrayDin SearchArrayDin(ArrayDin array, ElTypeArrayDin el)
{
	/*KAMUS LOKAL*/
	int i = 0, countArray = 0, countEl = 0;
	/*ALGORITMA*/
	int j = 0;
	while (el[j] != '\0')
	{
		countEl++;
		j++;
	}
	boolean found = false;
	while (i < array.Neff && !found)
	{
		// printf("countEl: %d\n", countEl);
		countArray = 0;
		j = 0;
		while (array.A[i][j] != '\0')
		{
			countArray++;
			j++;
		}
		// printf("countArray: %d, countEl: %d\n", countArray, countEl);

		j = 0;
		if (countArray == countEl)
		{
			// printf("masuk sini\n");
			boolean same = true;
			while (array.A[i][j] != '\0' && same)
			{
				// printf("array.A[i][j] = %c, el[j] = %c\n", array.A[i][j], el[j]);
				if (array.A[i][j] != el[j])
				{
					same = false;
				}
				else
				{
					j++;
				}
			}
			if (same)
			{
				found = true;
			}
		}
		i++;
	}
	// printf("i: %d\n", i);
	// printf("array.Neff: %d\n", array.Neff);
	if (!found)
	{
		return -1;
	}
	else
	{
		return i;
	}
}