#include <stdio.h>
#include "prioqueue.h"
#include "boolean.h"

/* *** Kreator *** */
void CreateQueuePQ(PrioQueue *q)
{
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyPQ(PrioQueue q)
{
	return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFullPQ(PrioQueue q)
{
	return (lengthPQ(q) == PQCAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthPQ(PrioQueue q)
{
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
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueuePQ(PrioQueue *q, PQElType val)
{
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
		// int idx = IDX_HEAD(*q);
		// while (((*q).buffer[IDX_HEAD(*q)].cookDuration > val.cookDuration) && (IDX_HEAD(*q) != (IDX_TAIL(*q))))
		// {
		// 	PQElType temp = (*q).buffer[IDX_HEAD(*q)];
		// 	(*q).buffer[IDX_HEAD(*q)] = (*q).buffer[IDX_HEAD(*q) + 1];
		// 	(*q).buffer[IDX_HEAD(*q) + 1] = temp;
		// 	IDX_HEAD(*q)
		// 	++;
		// }

		// IDX_HEAD(*q) = idx;

		// (*q).buffer[IDX_HEAD(*q)] = val;
	}
}
/* Proses: Menambahkan val pada q dengan aturan FIFO jika val belum ditemukan*/
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru jika val belum ditemukan, IDX_TAIL "mundur" dalam buffer melingkar. */

void enqueueCSQ(PrioQueue *q, PQElType val)
{
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

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeuePQ(PrioQueue *q, PQElType *val)
{
	*val = HEAD(*q);

	//
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

void dequeueAtIdx(PrioQueue *q, PQElType *val, int idx)
{
	// printf("dequeue at idx %d\n", idx);
	*val = (*q).buffer[idx];
	// printf("food id %d\n", (*val).foodID);
	// printf("cook duration %d\n", (*val).cookDuration);
	// printf("stay duration %d\n", (*val).stayDuration);
	// printf("price %d\n", (*val).price);

	//
	if (IDX_HEAD(*q) == IDX_TAIL(*q))
	{
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	}

	else
	{
		// printf("IDX_HEAD(*q) %d\n", IDX_HEAD(*q));
		// printf("IDX_TAIL(*q) %d\n", IDX_TAIL(*q));

		int i = IDX_HEAD(*q) + idx;
		while (i != IDX_TAIL(*q) + 1)
		{
			(*q).buffer[i] = (*q).buffer[i + 1];
			i = (i + 1) % PQCAPACITY;
		}
		IDX_TAIL(*q) = (IDX_TAIL(*q) - 1) % PQCAPACITY;
	}
}
/* Proses: Menghapus val pada q  pada indeks idx */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen q pada indeks idx pd I.S., IDX_TAIL "mundur";
		q mungkin kosong */

/* *** Display Queue *** */

void displayQueuePQ(PrioQueue q)
{
	if (isEmptyPQ(q))
	{
		printf("Queue is empty");
	}

	else
	{
		int i = IDX_HEAD(q);
		while (i != IDX_TAIL(q) + 1)
		{
			printf("food id : %d\n", q.buffer[i].foodID);
			printf("cook duration : %d\n", q.buffer[i].cookDuration);
			printf("stay duration: %d\n", q.buffer[i].stayDuration);
			printf("price: %d\n", q.buffer[i].price);
			i = (i + 1) % PQCAPACITY;
		}
	}
}
void displayTimePQ(PrioQueue q)
{
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
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void displayStayPQ(PrioQueue q)
{
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
