#include <stdio.h>
#include <stdlib.h>
#include "listMap.h"
#include "map.h"

int main() {
    ListMap L;
    createListMap(&L);
    printAllList(L);
}