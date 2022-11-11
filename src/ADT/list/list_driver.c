#include <stdio.h>
#include "list.h"

int main()
{
    List l = MakeList();

    printf("isEmpty : %d\n", IsEmptyList(l));

    for (int i = 0; i < 3; i++)
    {
        l.food[i].foodID = i;
        l.food[i].cookDuration = i;
        l.food[i].stayDuration = i;
        l.food[i].price = i * 10000;
    }

    PQElType foody;
    foody = GetListChar(l, 0);

    printf("foodID : %d\n", foody.foodID);
    printf("cookDuration : %d\n", foody.cookDuration);
    printf("stayDuraiton : %d\n", foody.stayDuration);
    printf("price : %d\n", foody.price);

    SetListChar(&l, 0, foody);

    printf("length : %d\n", LengthList(l));
    printf("firstIdx: %d\n", FirstIdxList(l));
    printf("lastIdx : %d\n", LastIdxList(l));

    printf("validList : %d\n", IsIdxValidList(l, 0));
    printf("effList : %d\n", IsIdxEffList(l, 0));

    printf("found : %d\n", SearchList(l, foody));

    PQElType foodies;
    foodies.foodID = 5;
    foodies.cookDuration = 5;
    foodies.stayDuration = 5;
    foodies.price = 50000;
    InsertFirstList(&l, foodies);
    // InsertAtList(&l, foodies, 3);
    InsertLastList(&l, foodies);

    displayTime(l);
    printf("\n");
    // PQElType foodiesOut;
    DeleteFirstList(&l);
    DeleteLastList(&l);

    displayTime(l);

    printf("\n");
    List l2 = MakeList();
    for (int i = 0; i < 6; i++)
    {
        l2.food[i].foodID = i;
        l2.food[i].cookDuration = i;
        l2.food[i].stayDuration = i;
        l2.food[i].price = i * 10000;
    }
    displayTime(l2);

    List l3 = ConcatList(l, l2);

    printf("%d\n", minList(l3));
    printf("\n");

    displayTime(l3);
    printf("\n");
    displayStay(l3);
    printf("\n");
    return 0;
}