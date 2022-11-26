/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"

#define NMax 50
#define BLANK '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

/* ********** KONSTRUKTOR ********** */
/* Prosedur untuk mengabaikan satu atau beberapa BLANK
 * I.S : currentChar sembarang
 * F.S : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreBlanks();

/* Prosedur untuk memulai pemrosesan kata
 * I.S : currentChar sembarang
 * F.S : EndWord = true, dan currentChar = MARK;
		  atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
		  currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD(char * FILE);

/* Prosedur untuk membaca input kata dari user 
 * I.S : currentChar sembarang
 * F.S : EndWord = true, dan currentChar = MARK;
 *	     atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
 *       currentChar karakter pertama sesudah karakter terakhir kata */
void STARTINPUTKATA();

/* Prosedur untuk memajukan kata yang akan diproses
 * I.S : currentChar adalah karakter pertama kata yang akan diakuisisi
 * F.S : currentWord adalah kata terakhir yang sudah diakuisisi,
 *		 currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
 *		 Jika currentChar = MARK, EndWord = true.
 * Proses : Akuisisi kata menggunakan procedure SalinWord */
void ADVWORD();

/* Prosedur untuk mengakuisisi kata, menyimpan dalam currentWord
 * I.S : currentChar adalah karakter pertama dari kata
 * F.S : currentWord berisi kata yang sudah diakuisisi;
		 currentChar = BLANK atau currentChar = MARK;
		 currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
		 Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWord();

/* ********** KONVERTER ********** */
/* Fungsi untuk merubah tipe data dari word menjadi integer. 
 * Mengembalikan nilai hasil convert dari word ke integer.
 * Prekondisi : pemrosesan telah berjalan */
int WordToInt(Word word);

/* Fungsi untuk Merubah tipe data dari word menjadi string. 
 * Mengembalikan nilai hasil convert dari word ke string. 
 * Prekondisi : pemrosesan telah berjalan */
char * WordToString (Word word);

/* Fungsi untuk merubah tipe data dari string menjadi word. 
 * Mengembalikan nilai hasil convert dari string ke word.
 * Prekondisi : pemrosesan telah berjalan */
Word StringtoWord (char*string);

/* ********** SELEKTOR ********** */
/* Fungsi untuk mengambil kata ke - {ke} dari suatu kalimat hasil input dari user. 
 * Prekondisi : pemrosesan telah berjalan */
Word takeword(Word command, int ke);

/* ********** OPERASI OPERASI ********** */
/* Fungsi untuk menggabungkan dua buah variabel bertipe char.
 * Dalam program ini, kedua variabel tersebut adalah path dan filename
 * Prekondisi : pemrosesan telah berjalan */
char * ConcateChar(char * path, char * filename);

/* ********** TEST KEBENARAN ********** */
/* Fungsi untuk mengembalikan true jika kata w tersebut sama dengan string c. 
 * Mengembalikan false jika kata w tidak sama dengan string c.
 * Prekondisi : pemrosesan telah berjalan */
boolean IsEqual(Word w, char *c);

/* Fungsi yang mengembalikan nilai kebenaran jika ada word yang dicari dalam mesin kata 
 * Prekondisi : pemrosesan telah berjalan */
boolean IsInWord(char* dicari, Word sumber);

void capsLock(char* huruf);
/* Membuat semua huruf menjadi uppercase */

void lowerCase(char* huruf);
/* Membuat semua huruf menjadi lowercase */

#endif
