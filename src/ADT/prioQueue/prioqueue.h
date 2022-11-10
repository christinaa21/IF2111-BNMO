/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __PRIO_QUEUE_H
#define __PRIO_QUEUE_H

#include "boolean.h"
// #include "../../games/diner_dash/diner_dash.h"

#define IDX_UNDEF -1
#define PQCAPACITY 100

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

/* *** KREATOR *** */
/* Prosedur untuk membuat queue
 * I.S : sembarang 
 * F.S : Sebuah q kosong terbentuk dengan kondisi sbb: 
 * 		 - Index head bernilai IDX_UNDEF 
 * 		 - Index tail bernilai IDX_UNDEF 
 * Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueuePQ(PrioQueue *q);

/* ********* PROTOTYPE ********* */
/*Fungsi yang mengirim true jika q kosong: lihat definisi di atas */
boolean isEmptyPQ(PrioQueue q);

/* Fungsi yang mengirim true jika tabel penampung elemen q sudah penuh
 * yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFullPQ(PrioQueue q);

/*Fungsi yang mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong.*/
int lengthPQ(PrioQueue q);

/* *** OPERASI OPERASI *** */
/* Proses: Menambahkan val pada q dengan aturan FIFO jika val belum ditemukan
 * I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh 
 * F.S : val menjadi TAIL yang baru jika val belum ditemukan, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueuePQ(PrioQueue *q, PQElType val);

/* Proses: Menambahkan val pada q dengan aturan FIFO 
 * I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh
 * F.S : val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueueCSQ(PrioQueue *q, PQElType val);

/* Proses: Menghapus val pada q  pada indeks idx 
 * I.S : q tidak mungkin kosong 
 * F.S : val = nilai elemen q pada indeks idx pd I.S., IDX_TAIL "mundur";
		q mungkin kosong */
void dequeuePQ(PrioQueue *q, PQElType *val);

/* *** DISPLAY QUEUE *** */
/* Proses : Menuliskan isi Queue dan infonya secara lengkap dengan traversal 
 * I.S : q boleh kosong 
 * F.S : Jika q tidak kosong akan ditampilkan daftar antrian
    	 Jika Queue kosong : Queue is empty */
void displayQueuePQ(PrioQueue q);

/* Proses : Menuliskan isi Queue makanan dan durasi masaknya dengan traversal 
 * I.S : q boleh kosong 
 * F.S : Jika q tidak kosong akan ditampilkan daftar antrian dan waktunya
    	 Jika Queue kosong tidak diproses */
void displayTimePQ(PrioQueue q);

/* Proses : Menuliskan isi Queue makanan dan durasi menunggu dengan traversal 
 * I.S : q boleh kosong 
 * F.S : Jika q tidak kosong akan ditampilkan daftar antrian dan waktunya
 *  	 Jika Queue kosong tidak diproses */
void displayStayPQ(PrioQueue q);

/* Fungsi yang akan mengeluarkan nilai kebenaran jika sebuah makanan ada di daftar secara transversal*/
boolean isMemberPQ(PrioQueue q, int id);
#endif