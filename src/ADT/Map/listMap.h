#ifndef __LISTMAP__
#define __LISTMAP__

#include "map.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSizeListMap 50
#define ElTypeMap Map

typedef int IdxTypeMap;

typedef struct
{
    ElTypeMap peta[10];
    int Neff;
} ListMap;

/* Prosedur untuk membuat list of map yang secara otomatis sudah terdiri dari 7 game.
 I.S. : terdefinisi
 F.S. : list of map terbuat */
void createListMap(ListMap *L);

/* Prosedur untuk memasukan map scoreboard game baru.
 I.S. : game baru dibuat user
 F.S. : scoreboard terbentuk */
void insertToList(ListMap *L, Map M);

/* Prosedur untuk menghapus semua data scoreboard di semua game.
 I.S. : terdefinsisi
 F.S. : semua scoreboard direset */
void resetAllMap(ListMap *L);

/* Prosedur untuk menghapus semua data scoreboard di sebuah game.
 I.S. : terdefinisi
 F.S. : scoreboard game direset */
void resetAtMap(ListMap *L, int n);

/* Prosedur untuk menghapus list map ke n.
 I.S. : terdefinisi
 F.S. : list berhasil dihapus */
void deleteListMapAt(ListMap *L, int n);

/* Prosedur untuk print semua scoreboard.
 I.S. : scoreboard terdefinisi
 F.S. : semua scoreboard berhasil diprint*/
void printAllList(ListMap L);

#endif