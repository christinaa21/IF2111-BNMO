#include <stdio.h>
#include "prioqueue.h"

int main()
{
    PQElType val;
    PrioQueue q;
    CreateQueuePQ(&q);

    printf("isEmpty: %d\n", isEmptyPQ(q));

    for (int i = 0; i < 3; i++)
    {
        val.foodID = i;
        val.cookDuration = i;
        val.stayDuration = i;
        val.price = i * 10000;
        enqueuePQ(&q, val);
    }
    displayQueuePQ(q);
    printf("\n");

    printf("isFull: %d\n", isFullPQ(q));
    printf("length : %d\n", lengthPQ(q));

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