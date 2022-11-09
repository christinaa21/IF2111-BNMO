#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize5
 */
ArrayDin MakeArrayDin(){
	ArrayDin array;
	(array).A = (ElTypeArrayDin*) malloc (InitialSize * sizeof(ElTypeArrayDin));
	(array).Capacity = InitialSize;
	(array).Neff = 0;
	return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
	free((*array).A);
	(*array).Capacity = 0;
	(*array).Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
	return ((array).Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
	return (array).Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayDin Get(ArrayDin array, IdxTypeArrayDin i){
	return ((array).A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
	return ((array).Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElTypeArrayDin el, IdxTypeArrayDin i){
	int length = Length(*array);
	int capacity = GetCapacity(*array);
	int j;

	if (length == capacity){
		int newCapacity = capacity + InitialSize;
		ElTypeArrayDin *arr = (ElTypeArrayDin *) malloc(newCapacity * sizeof(ElTypeArrayDin));
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
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElTypeArrayDin el){
	int nums = Length(*array);
	InsertAt(array, el, nums);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElTypeArrayDin el){
	InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxTypeArrayDin i){
	int length = Length(*array);
	int j;
	for (j = i; j < length - 1; j ++){
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array){
	int nums = Length(*array);
	DeleteAt(array, nums);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
	DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
	if (IsEmpty(array)){
		printf("[]\n");
	}
	else{
		printf("[");
		int i;
		for (i = 0; i < (array).Neff; i++){
			printf("%d", (array).A[i]);
			if (i < array.Neff - 1){
				printf(", ");
			}
		}
		printf("]\n");
	}
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
	int length = Length(*array);
	int i;
	for (i = 0; i < length/2; i ++){
		ElTypeArrayDin temp = (*array).A[i];
		(*array).A[i] = (*array).A[length - i -1];
		(*array).A[length - i - 1] = temp;
	}
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
	ArrayDin newArr = MakeArrayDin();
	int i;
	for (i = 0; i < array.Neff; i ++){
		InsertLast(&newArr, array.A[i]);
	}
	return newArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxTypeArrayDin SearchArrayDin(ArrayDin array, ElTypeArrayDin el){
	int i;
	for (i = 0; i < array.Neff; i++){
		if (array.A[i] == el){
			return i;
		}
	}
	return -1;
}