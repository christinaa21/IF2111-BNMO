#include <stdio.h>
#include <stdlib.h>
#include "listMap.h"
#include "map.h"

int main() {
    ListMap L;
    Map M; 
    printf("bikin list map -> print\n");
    createListMap(&L);
    printAllList(L);
    
    printf("nambahin list map -> print\n");
    insertToList(&L, M);
    InsertMap(&(L).peta[0], "ponyo", 12);
    printAllList(L);

    printf("reset 1 map -> print\n");
    resetAtMap(&L, 0);
    printAllList(L);

    printf("reset all map -> print\n");
    printf("before\n"); 
    InsertMap(&(L).peta[0], "ponyo", 12);
    InsertMap(&(L).peta[1], "nana", 10);
    printAllList(L);
    printf("after\n");
    resetAllMap(&L);
    printAllList(L);

    return 0;
}