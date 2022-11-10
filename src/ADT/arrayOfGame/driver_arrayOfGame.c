#include <stdio.h>
#include "../mesinkata/mesinkata.h"
#include "./arrayOfGame.h"

int main()
{
	ArrayOfGame arr, arr2;
	printf("Test ADT ArrayOfGame\n");
	printf("----------------------\n\n");
	printf("Membuat array kosong\n");
	arr = MakeArrayOfGame();
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("Capacity = %d\n", GetCapacityArrayOfGame(arr));
	printf("Length = %d\n", LengthArrayOfGame(arr));
	printf("IsEmpty = %d\n", IsEmptyArrayOfGame(arr));
	printf("----------------------\n");

	printf("Memasukkan elemen ke dalam array\n");
	printf("InsertLast RNG lalu Diner Dash\n");
	InsertGameLast(&arr, StringtoWord("RNG"));
	InsertGameLast(&arr, StringtoWord("Diner Dash"));
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("InsertFirst Dinosaur in Earth lalu Risewoman\n");
	InsertGameFirst(&arr, StringtoWord("Dinosaur in Earth"));
	InsertGameFirst(&arr, StringtoWord("Risewoman"));
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("InsertAt val: Hangman, idx: 2 dan val: Tic Tac Toe idx: 3\n");
	InsertGameAt(&arr, StringtoWord("Hangman"), 2);
	InsertGameAt(&arr, StringtoWord("Tic Tac Toe"), 3);
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("----------------------\n");

	printf("Menghapus elemen array\n");
	printf("DeleteLast\n");
	DeleteGameLast(&arr);
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("DeleteFirst\n");
	DeleteGameFirst(&arr);
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("DeleteAt idx ke-2\n");
	DeleteGameAt(&arr, 2);
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("----------------------\n");

	printf("Tes Capacity, Length, IsEmpty, dan IsFull lagi\n");
	printf("Capacity = %d\n", GetCapacityArrayOfGame(arr));
	printf("Length = %d\n", LengthArrayOfGame(arr));
	printf("IsEmpty = %d\n", IsEmptyArrayOfGame(arr));
	printf("----------------------\n");

	printf("Mereverse array\n");
	ReverseArrayOfGame(&arr);
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("----------------------\n");

	printf("Mengcopy array arr ke arr2\n");
	arr2 = MakeArrayOfGame();
	arr2 = CopyArrayOfGame(arr);
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("arr2 = ");
	PrintArrayOfGame(arr2);
	printf("----------------------\n");

	printf("Mencari index elemen array dengan value tertentu\n");
	printf("SearchArrayOfGame (Diner Dash) = %d\n", SearchArrayOfGame(arr, StringtoWord("Diner Dash")));
	printf("SearchArrayOfGame (Hangman) = %d\n", SearchArrayOfGame(arr, StringtoWord("Hangman")));
	printf("----------------------\n");

	printf("Tes Get Elemen Array\n");
	printf("arr = ");
	PrintArrayOfGame(arr);
	printf("Get (1) = %s\n", WordToString(GetGame(arr, 1)));
	printf("----------------------\n");

	printf("Dealokasi array\n");
	DeallocateArrayOfGame(&arr);
	DeallocateArrayOfGame(&arr2);
	printf("Capacity = %d\n", GetCapacityArrayOfGame(arr));
	printf("Length = %d\n", LengthArrayOfGame(arr));
	printf("Get elemen pertama = %d\n", GetGame(arr, 0));
	printf("-----------------------\n");
	return 0;
}