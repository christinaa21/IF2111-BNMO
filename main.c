#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "./src/game_util/game_util.h"
#include "./src/games/diner_dash/diner_dash.h"
#include "./src/games/random_number_generator/random_number_generator.h"
#include "./src/main_util/main_util.h"

int main()
{
    ArrayOfGame ListGame;
    Queue QueueGame;
    boolean cek = false;
    while(!cek){
        printf("Masukkan Command: ");
        STARTINPUTKATA();
        if(IsEqual(takeword(currentWord,1),"LOAD")){
            Word x = takeword(currentWord,2);
            load(WordToString(x),&ListGame);
            cek = true;
        }
        else if(IsEqual(takeword(currentWord,1),"START")){
            start();
            cek = true;
        }
        else {
            printf("Masukkan command START atau LOAD di awal permainan\n");
        }
    while (cek){
        printf("Masukkan Command: ");
        STARTINPUTKATA();
        if(IsEqual(currentWord,"CREATE GAME")){
            createGame(&ListGame);
        }
        else if(IsEqual(currentWord,"LIST GAME")){
            listGame(&ListGame);
        }
        else if(IsEqual(currentWord,"DELETE GAME")){
            deleteGame(&ListGame);
        }
        else if(IsEqual(currentWord,"QUEUE GAME")){
            queueGame(&QueueGame,ListGame);
        }
        else if(IsEqual(currentWord,"PLAY GAME")){
            playGame(&QueueGame);
        }
        else if(IsEqual(takeword(currentWord,1),"SKIPGAME")){
            listGame(&ListGame);
        }
        else if(IsEqual(currentWord,"HELP")){
            help();        
        }
    }
    }
    return 0;
}
// main file