#include <stdio.h>
#include "queue.h"
#include "boolean.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
	/* I.S. sembarang */
	/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
	/* - Index head bernilai IDX_UNDEF */
	/* - Index tail bernilai IDX_UNDEF */
	/* Proses : Melakukan alokasi, membuat sebuah q kosong */
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
	/* Mengirim true jika q kosong: lihat definisi di atas */
	return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFull(Queue q)
{
	/* Mengirim true jika tabel penampung elemen q sudah penuh */
	/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
	return (length(q) == CAPACITY);
}

int length(Queue q)
{
	/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
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

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQueue val)
{
	/* Proses: Menambahkan val pada q dengan aturan FIFO */
	/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
	/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
	// empty case
	if (isEmpty(*q))
	{
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	}

	else
	{
		// circular buffer
		IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
	}
	TAIL(*q).Length = val.Length;
	int i;
	for (i = 0; i < val.Length; i++)
	{
		TAIL(*q).TabWord[i] = val.TabWord[i];
	}
}

void dequeue(Queue *q, ElTypeQueue *val)
{
	/* Proses: Menghapus val pada q dengan aturan FIFO */
	/* I.S. q tidak mungkin kosong */
	/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
			q mungkin kosong */
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
	}
}

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
	/* Mengembalikan true jika x merupakan elemen dari q */
	ElTypeQueue val;
	char *xchar = WordToString(x);
	boolean notfound = true;
	while ((IDX_HEAD(q) != IDX_UNDEF) && notfound)
	{
		dequeue(&q, &val);
		if (IsEqual(val, xchar))
		{
			notfound = false;
		}
	}
	return !notfound;
}
