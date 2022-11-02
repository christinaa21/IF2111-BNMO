#ifndef __GAME_TAMBAHAN_H__
#define __GAME_TAMBAHAN_H__

#include <stdio.h>
#include <stdlib.h>

//Hapus aja kalo ga perlu
#include "../../../boolean.h"
#include "../../ADT/array/arraydin.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/prioQueue/prioqueue.h"

void gameTambahan(){
    printf("Game Over!\n");
    int skor;
    srand(time(NULL));
    skor=rand()%25;
    printf("Skor yang Anda peroleh: %d", skor);

}
// Game buatan pemain yang dibuat dengan command CREATE GAME
// Ketika dimainkan, akan langsung selesai & game over dengan skor akhir berupa integer random.

#endif