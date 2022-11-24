#ifndef __LISTMAP__
#define __LISTMAP__

#include "map.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10
#define ElTypeMap Map

typedef int IdxTypeMap;

typedef struct {
    ElTypeMap peta[10];
    int Neff;
} ListMap;

void createListMap(ListMap *L);

void insertToList(ListMap *L, Map M);

void deleteAllList(ListMap *L); 

void deleteAtMap(ListMap *L, int n);

void printAllList(ListMap L);
#endif