#include <stdio.h>
#include "queue.h"

int main()
{
    Word val;
    Queue q1, q2;
    ElTypeQueue g1, g2, g3, g4, g5;
    printf("Test ADT Queue\n");
    printf("----------------------\n\n");

    printf("Membuat array kosong\n");
    CreateQueue(&q1);
    printf("q1 = ");
    displayQueue(q1);
    printf("isEmpty: %d\n", isEmpty(q1));
    printf("isFull: %d\n", isFull(q1));
    printf("length: %d\n", length(q1));
    printf("----------------------\n");

    printf("Memasukkan (Enqueue) elemen ke dalam queue\n");
    enqueue(&q1, StringtoWord("Tes1"));
    enqueue(&q1, StringtoWord("Tes2"));
    enqueue(&q1, StringtoWord("Tes3"));
    enqueue(&q1, StringtoWord("Tes4"));
    enqueue(&q1, StringtoWord("Tes5"));
    printf("q1 = ");
    displayQueue(q1);
    printf("isEmpty: %d\n", isEmpty(q1));
    printf("isFull: %d\n", isFull(q1));
    printf("length: %d\n", length(q1));
    printf("----------------------\n");

    printf("Tes isInQueue\n");
    printf("isInQueue(Tes2) = %d\n", isInQueue(q1, StringtoWord("Tes2")));
    printf("isInQueue(Tes6) = %d\n", isInQueue(q1, StringtoWord("Tes6")));
    printf("----------------------\n");

    printf("Menyalin q1 ke q2 dengan copyQueue\n");
    CreateQueue(&q2);
    copyQueue(&q1, &q2);
    printf("q1 = ");
    displayQueue(q1);
    printf("q2 = ");
    displayQueue(q2);
    printf("----------------------\n");

    printf("Menghapus (Dequeue) elemen queue\n");
    while (!isEmpty(q1))
    {
        printf("q1 = ");
        displayQueue(q1);
        printf("isEmpty = %d\n", isEmpty(q1));
        printf("isFull = %d\n", isFull(q1));
        printf("length = %d\n", length(q1));
        printf("head = %d\n", IDX_HEAD(q1));
        printf("tail = %d\n", IDX_TAIL(q1));
        printf("----------------------\n");
        dequeue(&q1, &val);
        printf("dequeued = %s\n", WordToString(val));
    }
    printf("Keadaan saat queue kosong\n");
    displayQueue(q1);
    printf("isEmpty = %d\n", isEmpty(q1));
    printf("isFull = %d\n", isFull(q1));
    printf("length = %d\n", length(q1));
    printf("head = %d\n", IDX_HEAD(q1));
    printf("tail = %d\n", IDX_TAIL(q1));
    printf("----------------------\n");

    return 0;
}