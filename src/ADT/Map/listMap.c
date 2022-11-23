#include <stdio.h>
#include "listMap.h"
#include "map.h"


void createListMap(ListMap *L){
    (*L).Neff = 0;
}

void insertToList(ListMap *L, Map M){
    (*L).peta[(*L).Neff] = M;
    (*L).Neff++;
}

void displayListMap (ListMap *L, Map M){
    printf("**** SCOREBOARD %c ****\n", *L); 
    printf("| NAMA       | SKOR      |\n"); 
    printf("|------------------------|\n"); 
    for(int i =0; i<=(*L).Neff; i++){
        printf("| %c        | %d        |\n", (*L).peta[i].Key, (*L).peta[i].Value);
    }
}

void deleteAllList(ListMap *L){
    for (int i =0; i<=(*L).Neff; i++){
        (*L).peta[i] = Nil; 
        (*L).Neff --; 
    }
}