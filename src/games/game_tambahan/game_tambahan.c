#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_tambahan.h"

/* Game buatan pemain yang dibuat dengan command CREATE GAME
 * Ketika dimainkan, akan langsung selesai & game over dengan skor akhir berupa integer random. */
void gameTambahan(){
    printf("Game Over!\n");
    int skor;
    srand(time(NULL));
    skor=rand()%25;
    printf("Skor yang Anda peroleh: %d\n", skor);

}