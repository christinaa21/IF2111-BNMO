#include <stdio.h>
#include <stdlib.h>
#include "arrayOfGame.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayOfGame yang berisi game default dengan ukuran InitialSize
 */
ArrayOfGame MakeArrayOfGame()
{
	ArrayOfGame array;
	(array).A = (ElTypeArrayOfGame *)malloc(InitialSize * sizeof(ElTypeArrayOfGame));
	(array).Capacity = InitialSize;

	(array).Neff = 0;
	return array;
}

/**
 * Destruktor
 * I.S. ArrayOfGame terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayOfGame(ArrayOfGame *array)
{
	free((*array).A);
	(*array).Capacity = 0;
	(*array).Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayOfGame(ArrayOfGame array)
{
	return ((array).Neff == 0);
}

/**
 * Fungsi untuk mengetahui apakah suatu array penuh.
 * Prekondisi: array terdefinisi
 */
boolean IsFullArrayOfGame(ArrayOfGame array)
{
	return ((array).Neff == InitialSize);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayOfGame(ArrayOfGame array)
{
	return (array).Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayOfGame GetGame(ArrayOfGame array, IdxTypeArrayOfGame i)
{
	return ((array).A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrayOfGame(ArrayOfGame array)
{
	return ((array).Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertGameAt(ArrayOfGame *array, ElTypeArrayOfGame el, IdxTypeArrayOfGame i)
{
	int length = LengthArrayOfGame(*array);
	int capacity = GetCapacityArrayOfGame(*array);
	int j;

	if (length == capacity)
	{
		int newCapacity = capacity + InitialSize;
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
			(*array).A[j+1].TabWord[k] = (*array).A[j].TabWord[k];
		}
	}

	(*array).A[i].Length = el.Length;
	for (j = 0; j < el.Length; j++)
	{
		(*array).A[i].TabWord[j] = el.TabWord[j];
	}
	
	(*array).Neff++;
	// int temp = 0;

	// (*array).Neff++;

	// while (i <= (*array).Neff){
	// 	temp = (*array).A[i];
	// 	(*array).A[i] = el;
	// 	(*array).A[i + 1] = temp;
	// 	i++;
	// }
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertGameLast(ArrayOfGame *array, ElTypeArrayOfGame el)
{
	int nums = LengthArrayOfGame(*array);
	InsertGameAt(array, el, nums);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertGameFirst(ArrayOfGame *array, ElTypeArrayOfGame el)
{
	InsertGameAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayOfGame
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteGameAt(ArrayOfGame *array, IdxTypeArrayOfGame i)
{
	int length = LengthArrayOfGame(*array);
	int j;
	for (j = i; j < length - 1; j++)
	{
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayOfGame
 * Prekondisi: array tidak kosong
 */
void DeleteGameLast(ArrayOfGame *array)
{
	int nums = LengthArrayOfGame(*array);
	DeleteGameAt(array, nums);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayOfGame
 * Prekondisi: array tidak kosong
 */
void DeleteGameFirst(ArrayOfGame *array)
{
	DeleteGameAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayOfGame.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dengan setiap elemen (length,TabWord) dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayOfGame(ArrayOfGame array)
{
	Word w;
	char *s;
	printf("[");
	int i;
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
 * Prekondisi: array terdefinisi
 */
void ReverseArrayOfGame(ArrayOfGame *array)
{
	int length = LengthArrayOfGame(*array);
	int i;
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
	ArrayOfGame newArr = MakeArrayOfGame();
	int i;
	for (i = 0; i < array.Neff; i++)
	{
		InsertGameLast(&newArr, array.A[i]);
	}
	return newArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayOfGame.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxTypeArrayOfGame SearchArrayOfGame(ArrayOfGame array, ElTypeArrayOfGame el)
{
	IdxTypeArrayOfGame i = 0;
	boolean found = false;
	char *s1, *s2;
	while (i < array.Neff && !found)
	{
		s1 = WordToString(array.A[i]);
		s2 = WordToString(el);

		if (s1 == s2)
		{
			found = true;
		}
		i++;
	}

	if (found)
	{
		return i;
	} else {
		return -1;
	}
	
}