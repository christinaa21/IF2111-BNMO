#ifndef __TOWER_OF_HANOI_H__
#define __TOWER_OF_HANOI_H__

#include "../../ADT/stack/stack.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkata/mesinkarakter.h"
#include "../../../boolean.h"

void printTower(Stack tiangA, Stack tiangB, Stack tiangC, int n);
/* I.S. tiangA, tiangB, tiangC terdefinisi */
/* F.S. tiangA, tiangB, tiangC ditampilkan ke layar */

void inputTower(Word *tiangAwal, Word *tiangTujuan);
/* I.S. tiangAwal, tiangTujuan terdefinisi */
/* F.S. tiangAwal, tiangTujuan terisi */

boolean IsFullTower(Stack S, int n);
/* Mengirim true jika tiang sudah penuh */

void moveDisc(Stack *tiangAwal, Stack *tiangTujuan, int *move);
/* I.S. tiangAwal, tiangTujuan terdefinisi */
/* F.S. tiangAwal, tiangTujuan terisi */

int WordToIntStack(Word W);
/* Mengubah kata ke integer */

void TowerOfHanoi(int *score);
/* I.S. score terdefinisi */
/* F.S. score terisi */

#endif
