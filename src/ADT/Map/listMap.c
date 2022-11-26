#include <stdio.h>
#include "listMap.h"
#include "map.h"


void createListMap(ListMap *L){
    (*L).Neff = 6;
    Map MapRNG, MapDD, MapH, MapToH, MapSoM, MapTTT;
    CreateEmptyMap(&MapRNG); 
    CreateEmptyMap(&MapDD); 
    CreateEmptyMap(&MapH);
    CreateEmptyMap(&MapToH); 
    CreateEmptyMap(&MapSoM);
    CreateEmptyMap(&MapTTT);
    (*L).peta[0] = MapRNG;
    (*L).peta[1] = MapDD;
    (*L).peta[2] = MapH;
    (*L).peta[3] = MapToH;
    (*L).peta[4] = MapSoM;
    (*L).peta[5] = MapTTT;
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