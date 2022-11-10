#include <stdio.h>
#include "arraydin.h"

int main()
{
	ArrayDin arr, arr2;
	printf("Test ADT ArrayDin\n");
	printf("----------------------\n");
	printf("Catatan: PrintArrayDin sengaja dimodifikasi agar tidak ada koma,\nspasi, dan kurung siku untuk array yang tidak kosong.\nHal ini dilakukan karena diperlukan pada algoritma game Hangman.\n\n");
	printf("Membuat array kosong\n");
	arr = MakeArrayDin();
	printf("arr = ");
	PrintArrayDin(arr);
	printf("Capacity = %d\n", GetCapacity(arr));
	printf("Length = %d\n", Length(arr));
	printf("IsEmpty = %d\n", IsEmpty(arr));
	printf("----------------------\n");

	printf("Memasukkan elemen ke dalam array\n");
	printf("InsertLast 1 lalu 2\n");
	InsertLast(&arr, "1");
	InsertLast(&arr, "2");
	printf("arr = ");
	PrintArrayDin(arr);
	printf("InsertFirst 3 lalu 4\n");
	InsertFirst(&arr, "3");
	InsertFirst(&arr, "4");
	printf("arr = ");
	PrintArrayDin(arr);
	printf("InsertAt val: 5, idx: 2 dan val: 6 idx: 3\n");
	InsertAt(&arr, "5", 2);
	InsertAt(&arr, "6", 3);
	printf("arr = ");
	PrintArrayDin(arr);
	printf("----------------------\n");

	printf("Menghapus elemen array\n");
	printf("DeleteLast\n");
	DeleteLast(&arr);
	printf("arr = ");
	PrintArrayDin(arr);
	printf("DeleteFirst\n");
	DeleteFirst(&arr);
	printf("arr = ");
	PrintArrayDin(arr);
	printf("DeleteAt idx ke-2\n");
	DeleteAt(&arr, 2);
	printf("arr = ");
	PrintArrayDin(arr);
	printf("----------------------\n");

	printf("Tes Capacity, Length, IsEmpty, dan IsFull lagi\n");
	printf("Capacity = %d\n", GetCapacity(arr));
	printf("Length = %d\n", Length(arr));
	printf("IsEmpty = %d\n", IsEmpty(arr));
	printf("----------------------\n");

	printf("Mereverse array\n");
	ReverseArrayDin(&arr);
	printf("arr = ");
	PrintArrayDin(arr);
	printf("----------------------\n");

	printf("Mengcopy array arr ke arr2\n");
	arr2 = MakeArrayDin();
	arr2 = CopyArrayDin(arr);
	printf("arr = ");
	PrintArrayDin(arr);
	printf("arr2 = ");
	PrintArrayDin(arr2);
	printf("----------------------\n");

	printf("Mencari index elemen array dengan value tertentu\n");
	printf("SearchArrayDin (3) = %d\n", SearchArrayDin(arr, "3"));
	printf("SearchArrayDin (2) = %d\n", SearchArrayDin(arr, "2"));
	printf("----------------------\n");

	printf("Tes Get dan Set Elemen Array\n");
	printf("arr = ");
	PrintArrayDin(arr);
	printf("Get (1) = %s\n", Get(arr, 1));
	printf("Set 4 ke idx 2\n");
	Set(&arr, 2, "4");
	printf("arr = ");
	PrintArrayDin(arr);
	printf("----------------------\n");

	printf("Dealokasi array\n");
	DeallocateArrayDin(&arr);
	DeallocateArrayDin(&arr2);
	printf("Capacity = %d\n", GetCapacity(arr));
	printf("Length = %d\n", Length(arr));
	printf("Get elemen pertama = %d\n", Get(arr, 0));
	printf("-----------------------\n");
	return 0;
}