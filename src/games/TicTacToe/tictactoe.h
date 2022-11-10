#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../ADT/arrayOfGame/arrayOfGame.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../../boolean.h"

void board(ArrayOfGame arr);

int cekwin(ArrayOfGame arr);

void tictactoe();

#endif
