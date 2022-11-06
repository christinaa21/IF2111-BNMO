#include <stdio.h>
#include "ArrayOfGame.h"

int main()
{
	ArrayOfGame arr = MakeArrayOfGame();
	printf("capacity = %d\n", GetCapacity(arr));
	printf("length = %d\n", Length(arr));
	printf("%d\n", IsEmpty(arr));
	printf("%d\n", IsFull(arr));
	InsertLast(&arr, 1);
	InsertLast(&arr, 2);
	InsertFirst(&arr, 3);
	InsertFirst(&arr, 4);
	InsertAt(&arr, 5, 2);
	InsertAt(&arr, 6, 3);
	DeleteLast(&arr);
	DeleteFirst(&arr);
	DeleteAt(&arr, 2);
	PrintArrayDin(arr);
	ReverseArrayDin(&arr);
	PrintArrayDin(arr);
	ArrayOfGame arr2 = CopyArrayOfGame(arr);
	PrintArrayDin(arr2);
	SearchArrayDin(arr, 5);
	SearchArrayDin(arr, 6);
	return 0;
}