#include <stdio.h>
#include "prioqueue.h"
#include "boolean.h"

/* *** KREATOR *** */
/* Prosedur untuk membuat queue
 * I.S : sembarang 
 * F.S : Sebuah q kosong terbentuk dengan kondisi sbb: 
 * 		 - Index head bernilai IDX_UNDEF 
 * 		 - Index tail bernilai IDX_UNDEF 
 * Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueuePQ(PrioQueue *q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}


/* ********* PROTOTYPE ********* */
/*Fungsi yang mengirim true jika q kosong: lihat definisi di atas */
boolean isEmptyPQ(PrioQueue q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

/* Fungsi yang mengirim true jika tabel penampung elemen q sudah penuh
 * yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFullPQ(PrioQueue q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	return (lengthPQ(q) == PQCAPACITY);
}

/*Fungsi yang mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong.*/
int lengthPQ(PrioQueue q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (isEmptyPQ(q))
	{
		return 0;
	}

	else
	{
		int i = IDX_HEAD(q);
		int count = 1;
		while (i != IDX_TAIL(q))
		{
			count++;
			i = (i + 1) % PQCAPACITY;
		}
		return count;
	}
}

/* *** OPERASI OPERASI *** */
/* Proses: Menambahkan val pada q dengan aturan FIFO jika val belum ditemukan
 * I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh 
 * F.S : val menjadi TAIL yang baru jika val belum ditemukan, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueuePQ(PrioQueue *q, PQElType val)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (isEmptyPQ(*q))
	{
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
		TAIL(*q) = val;
	}

	else
	{
		boolean found = false;
		int i = IDX_HEAD(*q);
		while ((i != IDX_TAIL(*q) + 1) && !found)
		{
			if (val.foodID == (*q).buffer[i].foodID)
			{
				found = true;
			}
			i = (i + 1) % PQCAPACITY;
		}

		if (!found)
		{
			IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % PQCAPACITY;
			(*q).buffer[IDX_TAIL(*q)] = val;
		}
	}
}

/* Proses: Menambahkan val pada q dengan aturan FIFO 
 * I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh
 * F.S : val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueueCSQ(PrioQueue *q, PQElType val)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (isEmptyPQ(*q))
	{
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
		TAIL(*q) = val;
	}

	else
	{
		IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % PQCAPACITY;
		TAIL(*q) = val;
	}
}

/* Proses: Menghapus val pada q  pada indeks idx 
 * I.S : q tidak mungkin kosong 
 * F.S : val = nilai elemen q pada indeks idx pd I.S., IDX_TAIL "mundur";
		q mungkin kosong */
void dequeuePQ(PrioQueue *q, PQElType *val)
{
	/*KAMUS LOKAL*/
	*val = HEAD(*q);
	/*ALGORITMA*/
	if (IDX_HEAD(*q) == IDX_TAIL(*q))
	{
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	}

	else
	{
		IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % PQCAPACITY;
	}
}

/* *** DISPLAY QUEUE *** */
/* Proses : Menuliskan isi Queue dan infonya secara lengkap dengan traversal 
 * I.S : q boleh kosong 
 * F.S : Jika q tidak kosong akan ditampilkan daftar antrian
    	 Jika Queue kosong : Queue is empty */
void displayQueuePQ(PrioQueue q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (isEmptyPQ(q))
	{
		printf("Queue is empty");
	}
	else
	{
		PrioQueue temp;
		CreateQueuePQ(&temp);
		temp = q;
		PQElType val;
		while (!isEmptyPQ(temp))
		{
			dequeuePQ(&temp, &val);
			printf("M%d      | %d              | %d         | %d    \n", val.foodID, val.cookDuration, val.stayDuration, val.price);
		}
	}
}

/* Proses : Menuliskan isi Queue makanan dan durasi masaknya dengan traversal 
 * I.S : q boleh kosong 
 * F.S : Jika q tidak kosong akan ditampilkan daftar antrian dan waktunya
    	 Jika Queue kosong tidak diproses */
void displayTimePQ(PrioQueue q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (!isEmptyPQ(q))
	{
		int i = IDX_HEAD(q);
		while (i != IDX_TAIL(q) + 1)
		{
			if (q.buffer[i].cookDuration > 0)
			{
				printf("M%d      | %d              \n", q.buffer[i].foodID, q.buffer[i].cookDuration);
			}
			i = (i + 1) % PQCAPACITY;
		}
	}
}

/* Proses : Menuliskan isi Queue makanan dan durasi menunggu dengan traversal 
 * I.S : q boleh kosong 
 * F.S : Jika q tidak kosong akan ditampilkan daftar antrian dan waktunya
 *  	 Jika Queue kosong tidak diproses */
void displayStayPQ(PrioQueue q)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (!isEmptyPQ(q))
	{
		int i = IDX_HEAD(q);
		while (i != IDX_TAIL(q) + 1)
		{
			if (q.buffer[i].cookDuration == 0)
			{
				printf("M%d      | %d              \n", q.buffer[i].foodID, q.buffer[i].stayDuration);
			}
			i = (i + 1) % PQCAPACITY;
		}
	}
}

/* Fungsi yang akan mengeluarkan nilai kebenaran jika sebuah makanan ada di daftar secara transversal*/
boolean isMemberPQ(PrioQueue q, int id)
{
	/*KAMUS LOKAL*/

	/*ALGORITMA */
	if (!isEmptyPQ(q))
	{
		int i = IDX_HEAD(q);
		while (i != IDX_TAIL(q) + 1)
		{
			if (q.buffer[i].foodID == id)
			{
				return true;
			}
			i = (i + 1) % PQCAPACITY;
		}
	}
	return false;
}