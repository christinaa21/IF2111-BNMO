#include <stdio.h>
#include "queue.h"

int main() {
    int val;
    Queue q;
    CreateQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 12);
    enqueue(&q, 0);
    enqueue(&q, 3);
    enqueue(&q, 20);
    displayQueue(q);

    //dequeue(&q, &val);
    //dequeue(&q, &val);
    //enqueue(&q, 11);

    while (length(q) > 0) {
        displayQueue(q);
        printf("panjang : %d\n",length(q));
        printf("full : %d\n",isFull(q));
        printf("empty : %d\n",isEmpty(q));
        printf("head: %d\n",IDX_HEAD(q));
        printf("tail: %d\n",IDX_TAIL(q));
        printf("===========================\n");
        dequeue(&q, &val); 
        printf("dequeued : %d\n",val);
    }

    displayQueue(q);

    printf("panjang: %d\n",length(q));
    printf("full : %d\n",isFull(q));
    printf("empty : %d\n",isEmpty(q));
    printf("head: %d\n",IDX_HEAD(q));
    printf("tail: %d\n",IDX_TAIL(q));

    return 0;
}