#include <stdio.h>
#include <stdlib.h>
#include "arrayOfGame.h"

/* ********** KONSTRUKTOR ********** */
/* Proses pembentukan ArrayOfGame yang berisi game default dengan ukuran InitialSizeArrayOfGame.
 */
ArrayOfGame MakeArrayOfGame()
{
	/*KAMUS LOKAL*/
	ArrayOfGame array;
	/*ALGORITMA*/
	(array).A = (ElTypeArrayOfGame *)malloc(InitialSizeArrayOfGame * sizeof(ElTypeArrayOfGame));
	(array).Capacity = InitialSizeArrayOfGame;
	(array).Neff = 0;
	return array;
}

/* ********** DESTRUKTOR ********** */
/* I.S. ArrayOfGame terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayOfGame(ArrayOfGame *array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	free((*array).A);
	(*array).Capacity = 0;
	(*array).Neff = 0;
}

/* ********** TEST KOSONG/PENUH ********** */
/* Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayOfGame(ArrayOfGame array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((array).Neff == 0);
}

/**
 * Fungsi untuk mengetahui apakah suatu array penuh.
 * Prekondisi: array terdefinisi
 */
boolean IsFullArrayOfGame(ArrayOfGame array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((array).Neff == InitialSizeArrayOfGame);
}

/* ********** SELEKTOR ********** */
/* Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayOfGame(ArrayOfGame array)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (array).Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayOfGame GetGame(ArrayOfGame array, IdxTypeArrayOfGame i)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ((array).A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrayOfGame(ArrayOfGame array)
{
	/*KAMUS LOKAL*/

	/*ALGORTIMA*/
	return ((array).Capacity);
}

/* ********** OPERASI-OPERASI ********** */
/* Fungsi untuk menambahkan elemen baru di index ke-i
 * I.S	: array terdefinisi, i di antara 0..Length(array).
 * F.S 	: game baru berhasil ditambahkan di game pada indeks ke-i.
 */
void InsertGameAt(ArrayOfGame *array, ElTypeArrayOfGame el, IdxTypeArrayOfGame i)
{
	/*KAMUS LOKAL*/
	int length = LengthArrayOfGame(*array);
	int capacity = GetCapacityArrayOfGame(*array);
	int j;

	/*ALGORITMA*/
	if (length == capacity)
	{
		int newCapacity = capacity + InitialSizeArrayOfGame;
		ElTypeArrayOfGame *arr = (ElTypeArrayOfGame *)malloc(newCapacity * sizeof(ElTypeArrayOfGame));
		ElTypeArrayOfGame game;
		for (j = 0; j < length; j++)
		{
			game = GetGame(*array, j);
			arr[j].Length = game.Length;
			for (int k = 0; k < game.Length; k++)
			{
				arr[j].TabWord[k] = game.TabWord[k];
			}
		}
		free((*array).A);

		(*array).A = arr;
		(*array).Capacity = newCapacity;
	}

	for (j = length - 1; j >= i; j--)
	{
		(*array).A[j + 1].Length = (*array).A[j].Length;
		for (int k = 0; k < (*array).A[j].Length; k++)
		{
			(*array).A[j + 1].TabWord[k] = (*array).A[j].TabWord[k];
		}
	}

	(*array).A[i].Length = el.Length;
	for (j = 0; j < el.Length; j++)
	{
		(*array).A[i].TabWord[j] = el.TabWord[j];
	}

	(*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * I.S 	: array terdefinisi.
 * F.S	: game berhasil ditambahkan di akhir array.
 */
void InsertGameLast(ArrayOfGame *array, ElTypeArrayOfGame el)
{
	/*KAMUS LOKAL*/

	/*ALGORTIMA*/
	int nums = LengthArrayOfGame(*array);
	InsertGameAt(array, el, nums);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * I.S 	: array terdefinisi.
 * F.S	: game berhasil ditambahkan di awal array.
 */
void InsertGameFirst(ArrayOfGame *array, ElTypeArrayOfGame el)
{
	/*KAMUS LOKAL*/

	/*ALGORTIMA*/
	InsertGameAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayOfGame
 * I.S : array terdefinisi, i di antara 0..Length(array).
 * F.S : game berhasil dihapus pada indeks ke-i.
 */
void DeleteGameAt(ArrayOfGame *array, IdxTypeArrayOfGame i)
{
	/*KAMUS LOKAL*/
	int j;
	/*ALGORTIMA*/
	int length = LengthArrayOfGame(*array);
	for (j = i; j < length - 1; j++)
	{
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayOfGame
 * I.S : array tidak kosong dan array terdefinsi.
 * F.S : game di akhir array berhasil dihapus.
 */
void DeleteGameLast(ArrayOfGame *array)
{
	/*KAMUS LOKAL*/

	/*ALGORTIMA*/
	int nums = LengthArrayOfGame(*array);
	DeleteGameAt(array, nums);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayOfGame
 * I.S : array tidak kosong dan array terdefinisi.
 * F.S : game di awal array berhasil dihapus.
 */
void DeleteGameFirst(ArrayOfGame *array)
{
	/*KAMUS LOKAL*/

	/*ALGORTIMA*/
	DeleteGameAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayOfGame.
 * Proses 	: Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * 			  dengan setiap elemen (length,TabWord) dan diakhiri newline.
 * I.S 		: array terdefinisi.
 * F.S 		: array tertuliskan dilayar.
 */
void PrintArrayOfGame(ArrayOfGame array)
{
	/*KAMUS LOKAL*/
	Word w;
	char *s;
	int i;
	/*ALGORTIMA*/
	printf("[");
	for (i = 0; i < (array).Neff; i++)
	{
		w = (array).A[i];
		s = WordToString(w);
		printf("(%d,", w.Length);
		printf("%s)", s);

		if (i < array.Neff - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayOfGame.
 * I.S : array terdefinisi
 * F.S : array berhasil di-reverse.
 */
void ReverseArrayOfGame(ArrayOfGame *array)
{
	/*KAMUS LOKAL*/
	int length = LengthArrayOfGame(*array);
	int i;
	/*ALGORTIMA*/
	for (i = 0; i < length / 2; i++)
	{
		ElTypeArrayOfGame temp = (*array).A[i];
		(*array).A[i] = (*array).A[length - i - 1];
		(*array).A[length - i - 1] = temp;
	}
}

/**
 * Fungsi untuk melakukan copy suatu ArrayOfGame.
 * Prekondisi: array terdefinisi
 */
ArrayOfGame CopyArrayOfGame(ArrayOfGame array)
{
	/*KAMUS LOKAL*/
	ArrayOfGame newArr = MakeArrayOfGame();
	int i;
	/*ALGORITMA*/
	for (i = 0; i < array.Neff; i++)
	{
		InsertGameLast(&newArr, array.A[i]);
	}
	return newArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayOfGame.
 * Proses		: Index pertama yang ditemukan akan dikembalikan.
 * 				  Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi	: array terdefinisi
 */
IdxTypeArrayOfGame SearchArrayOfGame(ArrayOfGame array, ElTypeArrayOfGame el)
{
	/*KAMUS LOKAL*/
	IdxTypeArrayOfGame i = 0;
	boolean found = false;
	char *x;
	/*ALGORITMA*/
	x = WordToString(el);
	while (i < array.Neff && !found)
	{
		if (IsEqual(array.A[i], x))
		{
			found = true;
		}
		else
		{
			i++;
		}
	}

	if (found)
	{
		return i;
	}
	else
	{
		return -1;
	}
}