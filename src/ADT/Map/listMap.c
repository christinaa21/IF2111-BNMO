#include <stdio.h>
#include "listMap.h"

void createListMap(ListMap *L){
    (*L).Neff = 0;
}

void insertToList(ListMap *L, Map M){
    (*L).peta[(*L).Neff] = M;
    (*L).Neff++;
}

void displayListMap (ListMap *L){
    
}