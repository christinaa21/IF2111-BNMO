#ifndef SNAKEONMETEOR_H
#define SNAKEONMETEOR_H

#include "../../ADT/LinkedList/listdp.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkata/mesinkarakter.h"
#include "../../ADT/Point/point.h"
#include "../../../boolean.h"

char* IntToString(int x);

void printmap(List L, POINT M, POINT F, POINT O);

POINT Obstacle(List L);

POINT Food(List L, POINT Obstacle);

POINT Meteor(POINT Food, POINT Obstacle);

void UserMove(List L, char input, boolean *illegal_move, POINT Meteor);

void FirstRandSnake (List *L);

void SnakeOnMeteor(int* score);


#endif
