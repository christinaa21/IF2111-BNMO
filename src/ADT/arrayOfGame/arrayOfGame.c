#include <stdio.h>
#include <stdlib.h>
#include "ArrayOfGame.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayOfGame yang berisi game default dengan ukuran InitialSize
 */
ArrayOfGame MakeArrayOfGame(){
	ArrayOfGame array;
	(array).A = (ElTypeArrayOfGame*) malloc (InitialSize * sizeof(ElTypeArrayOfGame));
	(array).Capacity = InitialSize;

	STARTWORD("../../Data/list_game.txt");
	(array).A[0] = currentWord;
	for (int i = 1; i < 5; i++)	{
		ADVWORD();
		(array).A[i] = currentWord;
	}

	(array).Neff = 5;
	return array;
}

/**
 * Destruktor
 * I.S. ArrayOfGame terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayOfGame(ArrayOfGame *array){
	free((*array).A);
	(*array).Capacity = 0;
	(*array).Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array penuh.
 * Prekondisi: array terdefinisi
 */
boolean IsFull(ArrayOfGame array){
	return ((array).Neff == InitialSize);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayOfGame array){
	return (array).Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayOfGame Get(ArrayOfGame array, IdxTypeArrayOfGame i){
	return ((array).A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayOfGame array){
	return ((array).Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayOfGame *array, ElTypeArrayOfGame el, IdxTypeArrayOfGame i){
	int length = Length(*array);
	int capacity = GetCapacity(*array);
	int j;

	if (length == capacity){
		int newCapacity = capacity + InitialSize;
		ElTypeArrayOfGame *arr = (ElTypeArrayOfGame *) malloc(newCapacity * sizeof(ElTypeArrayOfGame));
		for (j = 0; j < length; j++){
			arr[j] = Get(*array, j);
		}
		free((*array).A);

		(*array).A = arr;
		(*array).Capacity = newCapacity;
	}

	for (j = length - 1; j >= i; j--){
		(*array).A[j+1] = (*array).A[j];
	}

	(*array).A[i] = el;
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
void InsertLast(ArrayOfGame *array, ElTypeArrayOfGame el){
	int nums = Length(*array);
	InsertAt(array, el, nums);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayOfGame *array, ElTypeArrayOfGame el){
	InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayOfGame
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayOfGame *array, IdxTypeArrayOfGame i){
	int length = Length(*array);
	int j;
	for (j = i; j < length - 1; j ++){
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayOfGame
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayOfGame *array){
	int nums = Length(*array);
	DeleteAt(array, nums);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayOfGame
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayOfGame *array){
	DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayOfGame.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dengan setiap elemen (length,TabWord) dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayOfGame(ArrayOfGame array){
	printf("[");
	int i;
	for (i = 0; i < (array).Neff; i++){
		printf("(%d,", (array).A[i].Length);
		printf("%s)", (array).A[i].TabWord);
		if (i < array.Neff - 1){
			printf(", ");
		}
	}
	printf("]\n");

}

/**
 * Fungsi untuk melakukan reverse suatu ArrayOfGame.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayOfGame(ArrayOfGame *array){
	int length = Length(*array);
	int i;
	for (i = 0; i < length/2; i ++){
		ElTypeArrayOfGame temp = (*array).A[i];
		(*array).A[i] = (*array).A[length - i -1];
		(*array).A[length - i - 1] = temp;
	}
}

/**
 * Fungsi untuk melakukan copy suatu ArrayOfGame.
 * Prekondisi: array terdefinisi
 */
ArrayOfGame CopyArrayOfGame(ArrayOfGame array){
	ArrayOfGame newArr = MakeArrayOfGame();
	int i;
	for (i = 0; i < array.Neff; i ++){
		InsertLast(&newArr, array.A[i]);
	}
	return newArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayOfGame.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxTypeArrayOfGame SearchArrayOfGame(ArrayOfGame array, ElTypeArrayOfGame el){
	int i;
	for (i = 0; i < array.Neff; i++){
		if (array.A[i].TabWord == el.TabWord && array.A[i].Length == el.Length){
			return i;
		}
	}
	return -1;
}