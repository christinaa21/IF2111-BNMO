/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __PRIO_QUEUE_H
#define __PRIO_QUEUE_H

#include "boolean.h"

#define IDX_UNDEF -1
#define PQCAPACITY 7

/* Definisi elemen dan address */
typedef struct
{
        /* data */
        int foodID;
        int cookDuration;
        int stayDuration;
        int price;
} PQElType;

typedef struct
{
        PQElType buffer[PQCAPACITY];
        int idxHead;
        int idxTail;
} PrioQueue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueuePQ(PrioQueue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyPQ(PrioQueue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullPQ(PrioQueue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthPQ(PrioQueue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueuePQ(PrioQueue *q, PQElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO jika val belum ditemukan*/
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru jika val belum ditemukan, IDX_TAIL "mundur" dalam buffer melingkar. */

void enqueueCSQ(PrioQueue *q, PQElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeuePQ(PrioQueue *q, PQElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void dequeueAtIdx(PrioQueue *q, PQElType *val, int idx);
/* Proses: Menghapus val pada q  pada indeks idx */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen q pada indeks idx pd I.S., IDX_TAIL "mundur";
                q mungkin kosong */

/* *** Display Queue *** */
void displayTimePQ(PrioQueue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void displayStayPQ(PrioQueue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
#endif