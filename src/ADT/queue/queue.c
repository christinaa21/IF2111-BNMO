#include <stdio.h>
#include "queue.h"
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
void enqueue(Queue *q, ElTypeQueue val)
{
	// empty case
	if (isEmpty(*q))
	{
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	}

	else
	{
		// pake circular buffer
		IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;

		// ini alt 2
		// // tail mentok
		// if ((IDX_TAIL(*q) + 1) % CAPACITY == 0){
		// 	int space = IDX_HEAD(*q);
		// 	int temp = IDX_TAIL(*q);
		// 	int i;
		// 	for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
		//           	(*q).buffer[i - space] = (*q).buffer[i];
		//       	}
		//       	IDX_HEAD(*q) = 0;
		//       	IDX_TAIL(*q) = temp - space;
		// }
		// IDX_TAIL(*q) ++;
	}
	TAIL(*q).Length = val.Length;
	int i;
	for (i = 0; i < val.Length; i++)
	{
		TAIL(*q).TabWord[i] = val.TabWord[i];
	}
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElTypeQueue *val)
{
	(*val).Length = HEAD(*q).Length;
	int i;
	for (i = 0; i < (*val).Length; i++)
	{
		(*val).TabWord[i] = HEAD(*q).TabWord[i];
	}

	//
	if (IDX_HEAD(*q) == IDX_TAIL(*q))
	{
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	}

	else
	{
		IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
		// ini alt 2
		// int i;
		// int space = IDX_HEAD(*q) + 1;
		// int temp = IDX_TAIL(*q);
		//       for (i = IDX_HEAD(*q) + 1; i <= IDX_TAIL(*q); i++) {
		//           (*q).buffer[i - space] = (*q).buffer[i];
		//       }
		//       IDX_HEAD(*q) = 0;
		//       IDX_TAIL(*q) = temp - space;
	}
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
		q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
	int i, temp1, temp2;
	ElTypeQueue val;
	if (isEmpty(q))
	{
		printf("[]");
	}
	else
	{
		temp1 = IDX_HEAD(q);
		temp2 = IDX_TAIL(q);
		printf("[");
		while (IDX_HEAD(q) != IDX_UNDEF)
		{
			dequeue(&q, &val);
			if (IDX_HEAD(q) == IDX_UNDEF)
			{
				printf("%d]", val);
			}
			else
			{
				printf("%d,", val);
			}
		}
		IDX_HEAD(q) = temp1;
		IDX_TAIL(q) = temp2;
	}
	printf("\n");
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void copyQueue(Queue *queueInput, Queue *queueOutput)
{
	/* Proses: Menyalin isi dari queueInput ke queueOutput */
	/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
	/* F.S. queueOutput memiliki isi queue yang sama */
	int i, len;
	Queue q;
	ElTypeQueue val;
	CreateQueue(&q);
	len = length(*queueInput);
	for (i = 0; i < len; i++)
	{
		dequeue(queueInput, &val);
		enqueue(queueOutput, val);
		enqueue(&q, val);
	}
	len = length(q);
	for (i = 0; i < len; i++)
	{
		dequeue(&q, &val);
		enqueue(queueInput, val);
	}
}

boolean isInQueue(Queue q, ElTypeQueue x)
{
	ElTypeQueue val;
	boolean notfound = true;
	while ((IDX_HEAD(q) != IDX_UNDEF) && notfound)
	{
		dequeue(&q, &val);
		if (val == x)
		{
			notfound = false;
		}
	}
	return !notfound;
}
