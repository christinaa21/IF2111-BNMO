#include <stdio.h>
#include "prioqueue.h"

int main()
{
    int val;
    PrioQueue q;
    CreateQueuePQ(&q);

    printf("isEmpty: %d\n", isEmptyPQ(q));

    for (int i = 0; i < 3; i++)
    {
        q.buffer[i].foodID = i;
        q.buffer[i].cookDuration = i;
        q.buffer[i].stayDuration = i;
        q.buffer[i].price = i * 10000;
    }

    printf("isFull: %d\n", isFullPQ(q));
    printf("length : %d\n", lengthPQ(q));
    displayQueuePQ(q);

    printf("\n");
    // printf("\n");
    displayTimePQ(q);
    printf("\n");

    displayStayPQ(q);
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        PQElType val;
        dequeuePQ(&q, &val);
        // printf("foodID : %d\n", val.foodID);
        // printf("cookDuration : %d\n", val.cookDuration);
        // printf("stayDuration : %d\n", val.stayDuration);
        // printf("price : %d\n", )
    }

    printf("isEmpty : %d\n", isEmptyPQ(q));
    printf("isFull : %d\n", isFullPQ(q));

    return 0;
}