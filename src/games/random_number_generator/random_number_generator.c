#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_number_generator.h"

/*** Penjelasan Permainan ***\
 * -	Permainan dimulai dengan menyediakan sebuah number random dari sistem
 * -    User akan memasukan sebuah angka untuk menebak
 * -    Sistem akan memberi informasi apakah nomor tebakan lebih besar atau lebih kecil
 * -    User akan terus memasukan input nomor hingga berhasil tertebak */
void RNG(){
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    srand(time(NULL));
    int X = rand() % 50;
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
    }
    printf("\nYa, X adalah %d\n\n", X);
    printf("--- GAME OVER ---\n");
}

