#include <stdio.h>
#include "listMap.h"
#include "map.h"

/* Prosedur untuk membuat list of map yang secara otomatis sudah terdiri dari 7 game.
 I.S. : terdefinisi
 F.S. : list of map terbuat */
void createListMap(ListMap *L){
    /*KAMUS LOKAL*/
    Map MapRNG, MapDD, MapH, MapToH, MapSoM, MapTTT;
    /*ALGORITMA*/
    (*L).Neff = 6;
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

/* Prosedur untuk memasukan map scoreboard game baru.
 I.S. : game baru dibuat user
 F.S. : scoreboard terbentuk */
void insertToList(ListMap *L, Map M){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*L).peta[(*L).Neff] = M;
    (*L).Neff++;
}

/* Prosedur untuk menghapus semua data scoreboard di semua game.
 I.S. : terdefinsisi
 F.S. : semua scoreboard direset */
void resetAllMap(ListMap *L){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    for (int i = 0; i<(*L).Neff; i++){
        CreateEmptyMap(&(*L).peta[i]);
    }
}

/* Prosedur untuk menghapus semua map di sebuah list.
 I.S. : terdefinisi
 F.S. : data pada list berhasil di reset */
void resetAtMap(ListMap *L, int n){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    for(int i =0; i<=n; i++){
        if (i == n) {
            CreateEmptyMap(&(*L).peta[i]);
        } else {
            i++;
        }
    }
}

/* Prosedur untuk menghapus list map ke n. 
 I.S. : terdefinisi 
 F.S. : list berhasil dihapus */
void deleteListMapAt(ListMap *L, int n){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    CreateEmptyMap(&(*L).peta[n-1]);
    for (int i = n-1; i<L->Neff; i++){
        (*L).peta[i] = (*L).peta[i+1];
    }
    (*L).Neff = (*L).Neff-1;
}

/* Prosedur untuk print semua list map. 
 I.S. : terdefinisi
 F.S. : semua list map berhasil diprint*/
void printAllList(ListMap L){
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    for (int i=0; i<L.Neff;i++){
        displayMap(L.peta[i]);
        printf("\n");
    }
} 