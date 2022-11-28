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
    printAllList(L);

    printf("reset 1 map -> print\n");
    resetAtMap(&L, 6);
    printAllList(L);

    printf("reset all map -> print\n");
    resetAllMap(&L);
    printAllList(L);

    return 0;
}