#include <stdio.h>
#include "../mesinkata/mesinkata.h"
#include "./arrayOfGame.h"

int main()
{
	ArrayOfGame arr = MakeArrayOfGame();
	char *pita = "../../../Data/gamelist.txt";
	ElTypeArrayOfGame g1, g2, g3, g4, g5;

	STARTWORD(pita);
	g1 = currentWord;
	ADVWORD();
	g2 = currentWord;
	ADVWORD();
	g3 = currentWord;
	ADVWORD();
	g4 = currentWord;
	ADVWORD();
	g5 = currentWord;
	
	printf("capacity = %d\n", GetCapacityArrayOfGame(arr));
	printf("length = %d\n", LengthArrayOfGame(arr));
	printf("is empty = %d\n", IsEmptyArrayOfGame(arr));
	InsertGameLast(&arr, g1);
	InsertGameLast(&arr, g2);
	printf("length = %d\n", LengthArrayOfGame(arr));
	PrintArrayOfGame(arr);
	printf("idx = %d\n", SearchArrayOfGame(arr, g1));
	
	InsertGameFirst(&arr, g3);
	InsertGameFirst(&arr, g4);
	InsertGameAt(&arr, g5, 2);
	InsertGameAt(&arr, g1, 3);
	PrintArrayOfGame(arr);
	DeleteGameLast(&arr);
	DeleteGameFirst(&arr);
	DeleteGameAt(&arr, 2);
	PrintArrayOfGame(arr);

	ReverseArrayOfGame(&arr);
	PrintArrayOfGame(arr);
	ArrayOfGame arr2 = CopyArrayOfGame(arr);
	PrintArrayOfGame(arr2);
	// SearchArrayOfGame(arr, g1);
	// SearchArrayOfGame(arr, g2);
	return 0;
}