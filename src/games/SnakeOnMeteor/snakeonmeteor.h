#ifndef SNAKEONMETEOR_H
#define SNAKEONMETEOR_H

#include "../../ADT/LinkedList/listdp.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkata/mesinkarakter.h"
#include "../../ADT/Point/point.h"
#include "../../../boolean.h"

char* IntToString(int x);

void printmap(Listdp L, POINT M, POINT F, POINT O);

POINT Obstacle(Listdp L);

POINT Food(Listdp L, POINT Obstacle);

POINT Meteor(POINT Food, POINT Obstacle);

void UserMove(Listdp L, char input, boolean *illegal_move, POINT Meteor);

void FirstRandSnake (Listdp *L);

void SnakeOnMeteor(int* score);


#endif
