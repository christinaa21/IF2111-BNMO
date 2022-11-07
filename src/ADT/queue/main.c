#include <stdio.h>
#include "queue.h"

int main() {
    int val;
    Queue q1, q2;
    CreateQueue(&q1);

    enqueue(&q1, 5);
    enqueue(&q1, 12);
    enqueue(&q1, 0);
    enqueue(&q1, 3);
    enqueue(&q1, 20);
    printf("q1 = ");
    displayQueue(q1);

    q2 = copyQueue(q1);
    printf("q2 = ");
    displayQueue(q2);

    printf("\n===========================\n");

    //dequeue(&q1, &val);
    //dequeue(&q1, &val);
    //enqueue(&q1, 11);

    while (length(q1) > 0) {
        printf("q1 = ");
        displayQueue(q1);
        printf("panjang : %d\n",length(q1));
        printf("full : %d\n",isFull(q1));
        printf("empty : %d\n",isEmpty(q1));
        printf("head: %d\n",IDX_HEAD(q1));
        printf("tail: %d\n",IDX_TAIL(q1));
        printf("===========================\n");
        dequeue(&q1, &val); 
        printf("dequeued : %d\n",val);
    }

    displayQueue(q1);

    printf("panjang: %d\n",length(q1));
    printf("full : %d\n",isFull(q1));
    printf("empty : %d\n",isEmpty(q1));
    printf("head: %d\n",IDX_HEAD(q1));
    printf("tail: %d\n",IDX_TAIL(q1));

    return 0;
}