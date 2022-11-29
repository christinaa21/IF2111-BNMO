#ifndef __ARRAY_OF_GAME__
#define __ARRAY_OF_GAME__

#include "../mesinkata/mesinkata.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxTypeArrayOfGame;
typedef Word ElTypeArrayOfGame;
typedef struct
{
    ElTypeArrayOfGame *A;
    int Capacity;
    int Neff;
} ArrayOfGame;

/**
 * Konstruktor
 * Proses pembentukan ArrayOfGame yang berisi game default dengan ukuran InitialSize.
 */
ArrayOfGame MakeArrayOfGame();

/**
 * Destruktor
 * I.S. ArrayOfGame terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayOfGame(ArrayOfGame *array);

/**
 * Fungsi untuk mengetahui apakah suatu array penuh.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayOfGame(ArrayOfGame array);

/**
 * Fungsi untuk mengetahui apakah suatu array penuh.
 * Prekondisi: array terdefinisi
 */
boolean IsFullArrayOfGame(ArrayOfGame array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayOfGame(ArrayOfGame array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayOfGame GetGame(ArrayOfGame array, IdxTypeArrayOfGame i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrayOfGame(ArrayOfGame array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * I.S	: array terdefinisi, i di antara 0..Length(array).
 * F.S 	: game baru berhasil ditambahkan di game pada indeks ke-i.
 */
void InsertGameAt(ArrayOfGame *array, ElTypeArrayOfGame el, IdxTypeArrayOfGame i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * I.S 	: array terdefinisi.
 * F.S	: game berhasil ditambahkan di akhir array.
 */
void InsertGameLast(ArrayOfGame *array, ElTypeArrayOfGame el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * I.S 	: array terdefinisi.
 * F.S	: game berhasil ditambahkan di awal array.
 */
void InsertGameFirst(ArrayOfGame *array, ElTypeArrayOfGame el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayOfGame
 * I.S : array terdefinisi, i di antara 0..Length(array).
 * F.S : game berhasil dihapus pada indeks ke-i.
 */
void DeleteGameAt(ArrayOfGame *array, IdxTypeArrayOfGame i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayOfGame
 * I.S : array tidak kosong dan array terdefinsi.
 * F.S : game di akhir array berhasil dihapus.
 */
void DeleteGameLast(ArrayOfGame *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayOfGame
 * I.S : array tidak kosong dan array terdefinisi.
 * F.S : game di awal array berhasil dihapus.
 */
void DeleteGameFirst(ArrayOfGame *array);

/**
 * Fungsi untuk melakukan print suatu ArrayOfGame.
 * Proses 	: Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * 			  dengan setiap elemen (length,TabWord) dan diakhiri newline.
 * I.S 		: array terdefinisi.
 * F.S 		: array tertuliskan dilayar.
 */
void PrintArrayOfGame(ArrayOfGame array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayOfGame.
 * I.S : array terdefinisi
 * F.S : array berhasil di-reverse.
 */
void ReverseArrayOfGame(ArrayOfGame *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayOfGame.
 * Prekondisi: array terdefinisi
 */
ArrayOfGame CopyArrayOfGame(ArrayOfGame array);

/**
 * Fungsi untuk melakukan search suatu ArrayOfGame.
 * Proses		: Index pertama yang ditemukan akan dikembalikan.
 * 				  Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi	: array terdefinisi
 */
IdxTypeArrayOfGame SearchArrayOfGame(ArrayOfGame array, ElTypeArrayOfGame el);

#endif