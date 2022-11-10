/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "../mesinkata/mesinkata.h"

#define IDX_UNDEF -1
#define CAPACITY 20

/* Definisi elemen dan address */
typedef Word ElTypeQueue;
typedef struct
{
        ElTypeQueue buffer[CAPACITY];
        int idxHead;
        int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** KREATOR *** */
/* I.S : sembarang */
/* F.S : Sebuah q kosong terbentuk dengan kondisi sbb: */
/* 		- Index head bernilai IDX_UNDEF */
/* 		- Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueue(Queue *q);


/* ********* PROTOTYPE ********* */
/* Fungsi yang mengirim true jika q kosong: lihat definisi di atas */
boolean isEmpty(Queue q);

/* Fungsi yang mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFull(Queue q);

/* Fungsi yang mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int length(Queue q);

/* *** OPERASI OPERASI *** */
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S : val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueue(Queue *q, ElTypeQueue val);

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S : q tidak mungkin kosong */
/* F.S : val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
		 q mungkin kosong */
void dequeue(Queue *q, ElTypeQueue *val);

/* *** Display Queue *** */
/* Prosedur untuk menampilkan Queue secara transversal*/
/* I.S : Queue terdefinisi */
/* F.S : Queue terlihat dilayar */
void displayQueue(Queue q);

/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S : queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S : queueOutput memiliki isi queue yang sama */
void copyQueue(Queue *queueInput, Queue *queueOutput);

/* Fungsi yang mengembalikan true jika x merupakan elemen dari q */
boolean isInQueue(Queue q, ElTypeQueue x);

#endif