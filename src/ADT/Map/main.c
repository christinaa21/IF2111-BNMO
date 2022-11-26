#include <stdio.h>
#include <stdlib.h>
#include "listMap.h"
#include "map.h"

void Playgame(ListMap *L) {
    char* nama = "Christina";
    int score = 10;
    InsertMap(&(*L).peta[0], nama, score);
}

int main() {
    ListMap L;
    createListMap(&L);
    printAllList(L);
    Playgame(&L);
    printAllList(L);
}