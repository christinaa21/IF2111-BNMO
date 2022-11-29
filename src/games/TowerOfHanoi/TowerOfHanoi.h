#ifndef __TOWER_OF_HANOI_H__
#define __TOWER_OF_HANOI_H__

#include "../../ADT/stack/stack.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkata/mesinkarakter.h"
#include "../../../boolean.h"

void printTower(Stack tiangA, Stack tiangB, Stack tiangC, int n);
void inputTower(Word *tiangAwal, Word *tiangTujuan);
boolean IsFullTower(Stack S, int n);
void moveDisc(Stack *tiangAwal, Stack *tiangTujuan, int *move);
int WordToIntStack(Word W);
void TowerOfHanoi(int *score);

#endif
