#ifndef __ARRAY_OF_GAME__
#define __ARRAY_OF_GAME__

#include "../mesinkata/mesinkata.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxTypeArrayDin;
typedef Word ElTypeArrayOfGame;
typedef struct {
    ElTypeArrayOfGame *A;
    int Capacity;
    int Neff;
} ArrayOfGame;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayOfGame kosong dengan ukuran InitialSize
 */
ArrayOfGame MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayOfGame terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayOfGame *array);
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayOfGame array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayOfGame array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayOfGame Get(ArrayOfGame array, IdxTypeArrayDin i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayOfGame array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayOfGame *array, ElTypeArrayOfGame el, IdxTypeArrayDin i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayOfGame *array, ElTypeArrayOfGame el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayOfGame *array, ElTypeArrayOfGame el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayOfGame
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayOfGame *array, IdxTypeArrayDin i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayOfGame
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayOfGame *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayOfGame
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayOfGame *array);

/**
 * Fungsi untuk melakukan print suatu ArrayOfGame.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayOfGame array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayOfGame.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayOfGame *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayOfGame.
 * Prekondisi: array terdefinisi
 */
ArrayOfGame CopyArrayDin(ArrayOfGame array);

/**
 * Fungsi untuk melakukan search suatu ArrayOfGame.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxTypeArrayDin SearchArrayDin(ArrayOfGame array, ElTypeArrayOfGame el);

#endif