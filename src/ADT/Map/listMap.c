#include <stdio.h>
#include "listMap.h"
#include "map.h"


void createListMap(ListMap *L){
    (*L).Neff = 5;
    Map MapRNG, MapDD, MapDiE, MapRW, MapET;
    CreateEmptyMap(&MapRNG); 
    CreateEmptyMap(&MapDD); 
    CreateEmptyMap(&MapDiE);
    CreateEmptyMap(&MapRW); 
    CreateEmptyMap(&MapET);
}

void insertToList(ListMap *L, Map M){
    (*L).peta[(*L).Neff] = M;
    (*L).Neff++;
}

void deleteAllList(ListMap *L){
    (*L).Neff = Nil;
}

void deleteAtMap(ListMap *L, int n){
    for(int i =0; i<=n; i++){
        if (i == n) {
            Map M;
            DeleteAllMap(&M);
        } else {
            i++;
        }
    }
}

void printAllList(ListMap L){
    for (int i=0; i<L.Neff;i++){
        displayMap(L.peta[i]);
        printf("\n");
    }
}