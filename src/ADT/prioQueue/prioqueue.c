#include <stdio.h>
#include "prioqueue.h"
#include "boolean.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
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
boolean isEmpty(Queue q)
{
	return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q)
{
	return (length(q) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q)
{
	if (isEmpty(q))
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
			i = (i + 1) % CAPACITY;
		}
		return count;
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
	if (isEmpty(*q))
	{
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
		HEAD(*q) = val;
	}

	else
	{
		IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
		int idx = IDX_HEAD(*q);
		while (((*q).buffer[IDX_HEAD(*q)].cookDuration > val.cookDuration) && (IDX_HEAD(*q) != (IDX_TAIL(*q))))
		{
			ElType temp = (*q).buffer[IDX_HEAD(*q)];
			(*q).buffer[IDX_HEAD(*q)] = (*q).buffer[IDX_HEAD(*q) + 1];
			(*q).buffer[IDX_HEAD(*q) + 1] = temp;
			IDX_HEAD(*q)
			++;
		}

		IDX_HEAD(*q) = idx;

		(*q).buffer[IDX_HEAD(*q)] = val;
	}
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val)
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
		IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
	}
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
		q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
	if (isEmpty(q))
	{
		printf("[]\n");
	}
	else
	{
		ElType val;
		// alt 3
		printf("[");

		while (!isEmpty(q))
		{
			dequeue(&q, &val);
			printf("%d", val);
			if (!isEmpty(q))
			{
				printf(",");
			}
		}
		printf("]\n");
	}
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
