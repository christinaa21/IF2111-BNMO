#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 50

typedef int IdxTypeArrayDin;
typedef char *ElTypeArrayDin;
typedef struct
{
    ElTypeArrayDin *A;
    int Capacity;
    int Neff;
} ArrayDin;

/* ********** KONSTRUKTOR ********** */
/* Proses Pembentukan ArrayDin kosong dengan ukuran InitialSize.
 */
ArrayDin MakeArrayDin();

/* ********** DESTRUKTOR ********** */
/* I.S. ArrayDin terdefinisi.
 * F.S. array->A terdealokasi.
 */
void DeallocateArrayDin(ArrayDin *array);

/* ********** TEST KOSONG/PENUH ********** */
/* Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi.
 */
boolean IsEmpty(ArrayDin array);

/* ********** SELEKTOR ********** */
/* Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi.
 */
int Length(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrayDin GetArrayDin(ArrayDin array, IdxTypeArrayDin i);

/**
 * Fungsi untuk mengeset x pada elemen array dengan indeks ke-i.
 * Prekondisi: array, i, dan x terdefinisi.
 */
void SetArrayDin(ArrayDin *array, IdxTypeArrayDin i, ElTypeArrayDin x);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi.
 */
int GetCapacity(ArrayDin array);

/* ********** OPERASI-OPERASI ********** */
/* Fungsi untuk menambahkan elemen baru di index ke-i.
 * I.S : array terdefinisi, i di antara 0..Length(array).
 * F.S : sebuah elemen berhasil ditambahkan pada indeks ke-1.
 */
void InsertAt(ArrayDin *array, ElTypeArrayDin el, IdxTypeArrayDin i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * I.S : array terdefinisi.
 * F.S : elemen baru berhasil ditambahkan di akhir array.
 */
void InsertLast(ArrayDin *array, ElTypeArrayDin el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * I.S : array terdefinisi.
 * F.S : elemen baru berhasil ditambahkan di awal array.
 */
void InsertFirst(ArrayDin *array, ElTypeArrayDin el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * I.S : array terdefinisi, i di antara 0..Length(array).
 * F.S : elemen pada indeks ke-i berhasil dihapuskan dari array.
 */
void DeleteAt(ArrayDin *array, IdxTypeArrayDin i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * I.S : array tidak kosong dan terdefinisi.
 * F.S : elemen terakhir pada array berhasil dihapuskan.
 */
void DeleteLast(ArrayDin *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * I.S : array tidak kosong dan array terdefinisi.
 * F.S : elemen pertama pada array berhasil dihapuskan.
 */
void DeleteFirst(ArrayDin *array);

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Proses 	: Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * 			  dan diakhiri newline.
 * I.S 		: array terdefinisi.
 * F.S 		: array tertuliskan dilayar.
 */
void PrintArrayDin(ArrayDin array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * I.S : array terdefinisi.
 * F.S : array berhasil di-reverse.
 */
void ReverseArrayDin(ArrayDin *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi.
 */
ArrayDin CopyArrayDin(ArrayDin array);

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Proses 		: Index pertama yang ditemukan akan dikembalikan.
 * 				  Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi	: array terdefinisi.
 */
IdxTypeArrayDin SearchArrayDin(ArrayDin array, ElTypeArrayDin el);

#endif