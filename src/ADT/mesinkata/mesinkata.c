#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

/*KAMUS*/
boolean EndWord = false;
Word currentWord;

/* ********** KONSTRUKTOR ********** */
/* Prosedur untuk mengabaikan satu atau beberapa BLANK
 * I.S : currentChar sembarang
 * F.S : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreBlanks()
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	while ((currentChar == BLANK) && (currentChar != MARK))
	{
		ADV();
	}
}

/* Prosedur untuk memulai pemrosesan kata
 * I.S : currentChar sembarang
 * F.S : EndWord = true, dan currentChar = MARK;
		  atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
		  currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD(char *FILE)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
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

/* Prosedur untuk membaca input kata dari user
 * I.S : currentChar sembarang
 * F.S : EndWord = true, dan currentChar = MARK;
 *	     atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
 *       currentChar karakter pertama sesudah karakter terakhir kata */
void STARTINPUTKATA()
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
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

/* Prosedur untuk memajukan kata yang akan diproses
 * I.S : currentChar adalah karakter pertama kata yang akan diakuisisi
 * F.S : currentWord adalah kata terakhir yang sudah diakuisisi,
 *		 currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
 *		 Jika currentChar = MARK, EndWord = true.
 * Proses : Akuisisi kata menggunakan procedure SalinWord */
void ADVWORD()
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
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

/* Prosedur untuk mengakuisisi kata, menyimpan dalam currentWord
 * I.S : currentChar adalah karakter pertama dari kata
 * F.S : currentWord berisi kata yang sudah diakuisisi;
		 currentChar = BLANK atau currentChar = MARK;
		 currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
		 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWord()
{
	/*KAMUS LOKAL*/
	int i = 0;
	/*ALGORITMA*/
	while ((!EOP) && (currentChar != BLANK) && (i < NMax))
	{
		currentWord.TabWord[i] = currentChar;
		ADV();
		i++;
	}
	currentWord.Length = i;
}

/* ********** KONVERTER ********** */
/* Fungsi untuk merubah tipe data dari word menjadi integer.
 * Mengembalikan nilai hasil convert dari word ke integer.
 * Prekondisi : pemrosesan telah berjalan */
int WordToInt(Word word)
{
	/*KAMUS LOKAL*/
	int hasil = 0;
	int i;
	/*ALGORITMA*/
	hasil += word.TabWord[0] - 48;
	for (i = 1; i < word.Length; i++)
	{
		hasil *= 10;
		hasil += word.TabWord[i] - 48;
	}
	return hasil;
}

/* Fungsi untuk Merubah tipe data dari word menjadi string.
 * Mengembalikan nilai hasil convert dari word ke string.
 * Prekondisi : pemrosesan telah berjalan */
char *WordToString(Word word)
{
	/*KAMUS LOKAL*/
	int i;
	/*ALGORITMA*/
	char *C = malloc(word.Length * sizeof(char));
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

/* Fungsi untuk merubah tipe data dari string menjadi word.
 * Mengembalikan nilai hasil convert dari string ke word.
 * Prekondisi : pemrosesan telah berjalan */
Word StringtoWord(char *string)
{
	/*KAMUS LOKAL*/
	Word kata;
	int i = 0;
	kata.Length = 0;
	/*ALGORITMA*/
	while (string[i] != '\0')
	{
		kata.TabWord[i] = string[i];
		kata.Length++;
		i++;
	}
	return kata;
}

/* ********** SELEKTOR ********** */
/* Fungsi untuk mengambil kata ke - {ke} dari suatu kalimat hasil input dari user.
 * Prekondisi : pemrosesan telah berjalan */
Word takeword(Word command, int ke)
{
	/*KAMUS LOKAL*/
	Word w;
	int i = 0;
	int j = 0;
	/*ALGORITMA*/
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

/* ********** OPERASI OPERASI ********** */
/* Fungsi untuk menggabungkan dua buah variabel bertipe char.
 * Dalam program ini, kedua variabel tersebut adalah path dan filename
 * Prekondisi : pemrosesan telah berjalan */
char *ConcateChar(char *path, char *filename)
{
	/*KAMUS LOKAL*/
	int i;
	int j = 0;
	/*ALGORITMA*/
	Word dir = StringtoWord(path);
	Word file = StringtoWord(filename);
	int len = dir.Length + file.Length;
	for (i = dir.Length; i < len; i++)
	{
		dir.TabWord[i] = file.TabWord[j];
		dir.Length++;
		j++;
	}
	char *dir_file = WordToString(dir);
	return dir_file;
}

/* ********** TEST KEBENARAN ********** */
/* Fungsi untuk mengembalikan true jika kata w tersebut sama dengan string c.
 * Mengembalikan false jika kata w tidak sama dengan string c.
 * Prekondisi : pemrosesan telah berjalan */
boolean IsEqual(Word w, char *c)
{
	/*KAMUS LOKAL*/
	boolean equal = true;
	int i = 0, ctr = 0;
	/*ALGORITMA*/
	while (c[i] != '\0')
	{
		i++;
	}
	ctr = i;

	if (w.Length != ctr)
	{
		equal = false;
	}

	else
	{
		for (i = 0; i < w.Length; i++)
		{
			if (w.TabWord[i] != c[i])
			{
				equal = false;
			}
		}
	}
	return equal;
}

/* Fungsi yang mengembalikan nilai kebenaran jika ada word yang dicari dalam mesin kata
 * Prekondisi : pemrosesan telah berjalan */
boolean IsInWord(char *dicari, Word sumber)
{
	/*KAMUS LOKAL*/
	boolean notfound = true;
	int i = 0;
	/*ALGORTIMA*/
	while ((notfound) && (i < sumber.Length))
	{
		if (sumber.TabWord[i] == dicari[0])
		{
			notfound = false;
		}
		else
		{
			i++;
		}
	}
	return !notfound;
}

void capsLock(char *huruf)
{
	int i = 0;
	while (huruf[i] != '\0')
	{
		if ((huruf[i] >= 97) && (huruf[i] <= 122))
		{
			huruf[i] -= 32;
		}
		i++;
	}
}
/* Membuat semua huruf menjadi uppercase */

void lowerCase(char *huruf)
{
	int i = 0;
	while (huruf[i] != '\0')
	{
		if ((huruf[i] >= 65) && (huruf[i] <= 90))
		{
			huruf[i] += 32;
		}
		i++;
	}
}
/* Membuat semua huruf menjadi uppercase */