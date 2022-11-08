#include <stdio.h>
#include <stdlib.h>
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

void STARTWORD(char *FILE)
{
	START(FILE);
	IgnoreBlanks();

	if (EOP)
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

void STARTINPUTKATA()
{
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

void ADVWORD()
{
	IgnoreBlanks();
	if (EOP)
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
	while ((!EOP) && (currentChar != BLANK) && (i < NMax))
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
	for (i = 1; i < word.Length; i++)
	{
		hasil *= 10;
		hasil += word.TabWord[i] - 48;
	}
	return hasil;
}
/* Merubah tipe data dari word menjadi integer
Mengembalikan nilai hasil convert dari word ke integer*/

char *WordToString(Word word)
{
	char *C = malloc(word.Length * sizeof(char));
	int i;
	while (C == NULL)
	{
		C = malloc(word.Length * sizeof(char));
	}
	for (i = 0; i < word.Length; i++)
	{
		C[i] = word.TabWord[i];
	}
	C[i] = '\0';
	return C;
}
/*Merubah tipe data dari word menjadi string
Mengembalikan nilai hasil convert dari word ke string*/

Word takeword(Word command, int ke)
{
	Word w;
	int i = 0;
	int j = 0;
	while (j != ke - 1 && i < command.Length)
	{
		if (command.TabWord[i] == ' ')
		{
			j++;
		}
		i++;
		if (i == command.Length)
		{
			j++;
		}
	}
	boolean cek = false;
	int length = 0;
	while (i < command.Length && !cek)
	{
		if (command.TabWord[i] == ' ')
		{
			cek = true;
		}
		else
		{
			w.TabWord[length] = command.TabWord[i];
			length++;
			i++;
		}
	}
	w.Length = length;
	return w;
}
/* Mengambil kata ke - {ke} dari suatu kalimat hasil input dari user
 */

boolean IsEqual(Word w, char *c)
{
	boolean equal = true;
	int i;
	for (i = 0; i < w.Length; i++)
	{
		if (w.TabWord[i] != c[i])
		{
			equal = false;
		}
	}
	return equal;
}
/* Mengembalikan true jika kata w tersebut sama dengan string c
Mengembalikan false jika kata w tidak sama dengan string c
*/

// int main() {
// 	char* file = "file.txt";
// 	STARTWORD(file);
// 	char* kata;
// 	printf("WordLength: %d\n", currentWord.Length);
// 	kata = WordToString(currentWord);
// 	printf("%s\n", kata);
// 	int kata_int = WordToInt(currentWord);
// 	printf("%d\n", kata_int);
// 	while (!IsEOP()) {
// 		ADVWORD();
// 		printf("WordLength: %d\n", currentWord.Length);
// 		kata = WordToString(currentWord);
// 		printf("%s\n", kata);
// 	}
// 	STARTINPUTKATA();
// 	printf("WordLength: %d\n", currentWord.Length);
// 	kata = WordToString(currentWord);
// 	printf("%s\n", kata);
// }