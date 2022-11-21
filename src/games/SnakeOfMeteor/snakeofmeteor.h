#ifndef SNAKEOFMETEOR_H
#define SNAKEOFMETEOR_H

#include "../../ADT/LinkedList/listdp.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkata/mesinkarakter.h"
#include "../../ADT/Point/point.h"
#include "../../../boolean.h"

void printmap(List L, POINT M, POINT F);

POINT Food(List L);

POINT Meteor(POINT Food);

void UserMove(List L, char input, boolean *GameOver);

void FirstRandSnake (List *L);

void SnakeOfMeteor();


#endif
