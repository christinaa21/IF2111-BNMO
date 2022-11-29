#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_number_generator.h"

/*** Penjelasan Permainan ***\
 * -	Permainan dimulai dengan menyediakan sebuah number random dari sistem
 * -    User akan memasukan sebuah angka untuk menebak
 * -    Sistem akan memberi informasi apakah nomor tebakan lebih besar atau lebih kecil
 * -    User akan terus memasukan input nomor hingga berhasil tertebak */
void RNG(int *score){
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    srand(time(NULL));
    int X = rand() % 50;
    int count = 1;
    printf("Tebakan: ");
    STARTINPUTKATA();
    while (WordToInt(currentWord)!=X){
        if (WordToInt(currentWord)>X){
            printf("Lebih kecil\n");
        }
        else if(WordToInt(currentWord)<X){
            printf("Lebih besar\n");
        }
        printf("Tebakan: ");
        STARTINPUTKATA();
        count++;
    }
    printf("\nYa, X adalah %d\n\n", X);
    printf("--- GAME OVER ---\n");
    *score = 100 - count;
    printf("Skor yang Anda peroleh adalah: %d\n", *score);
}

