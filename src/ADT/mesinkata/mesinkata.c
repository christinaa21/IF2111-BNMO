#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord = false;
Word currentWord;

void IgnoreBlanks()
{
	while ((currentChar == BLANK) && (currentChar != MARK))
	{
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char * FILE)
{
	START(FILE);
	IgnoreBlanks();

	if (IsEOP())
	{
		EndWord = true;
	}

	else
	{
		EndWord = false;
		CopyWord();
	}
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
		  atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
		  currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
	IgnoreBlanks();
	if (IsEOP())
	{
		EndWord = true;
	}

	else
	{
		EndWord = false;
		CopyWord();
	}
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
		  currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
		  Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
	// typedef struct
	// {
	//   		char TabWord[NMax];  container penyimpan kata, indeks yang dipakai [0..NMax-1]
	//   		int Length;
	// } Word;
	int i = 0;
	while ((!EOP) && (currentChar != BLANK) && (i<NMax))
	{
		currentWord.TabWord[i] = currentChar;
		ADV();
		i++;
		
	}
	currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
		  currentChar = BLANK atau currentChar = MARK;
		  currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
		  Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int WordToInt(Word word)
{
    int hasil = 0;
    int i;
    hasil += word.TabWord[0] - 48;
    if (word.Length > 1)
    {
        for (i = 1; i < word.Length; i++)
        {
            hasil *= 10;
            hasil += word.TabWord[i] - 48;
        }
    }

    return hasil;
}

void STARTINPUTKATA(){
	STARTINPUT();
    if (currentChar == '\0')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
