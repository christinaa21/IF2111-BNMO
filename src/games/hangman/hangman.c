#include <stdio.h>
#include "hangman.h"

void capsLock(char* huruf) {
    if ((huruf[0] >= 97) && (huruf[0] <= 122)) {
        huruf[0]-=32;
    }
}
/* Membuat semua huruf menjadi uppercase */

void hangMan() {
    // Game bonus
    ArrayDin ArrayKata;
    ArrayKata = MakeArrayDin();
    InsertLast(&ArrayKata, "ALSTRUKDAT");
    InsertLast(&ArrayKata, "PBD");
    InsertLast(&ArrayKata, "PRAKTIKUM");
    InsertLast(&ArrayKata, "TUBES");
    InsertLast(&ArrayKata, "PROBSTAT");
    InsertLast(&ArrayKata, "OMPI");
    InsertLast(&ArrayKata, "MILESTONE");
    InsertLast(&ArrayKata, "UTS");
    InsertLast(&ArrayKata, "BNMO");
    InsertLast(&ArrayKata, "UAS");
    InsertLast(&ArrayKata, "KEOS");
    InsertLast(&ArrayKata, "ARSIKOM");
    InsertLast(&ArrayKata, "MATSTI");
    InsertLast(&ArrayKata, "EDUNEX");
    InsertLast(&ArrayKata, "SIX");

    srand(time(NULL));
    int X = rand() % 15;
    char* tebakan = Get(ArrayKata, X);
    Word tertebak = StringtoWord(tebakan);
    Word tebakan1 = StringtoWord(tebakan);

    ArrayDin ArrayHangman;
    ArrayHangman = MakeArrayDin();
    InsertLast(&ArrayHangman, "_________\n|         \n|         \n|         \n|         \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|         \n|         \n|         \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|         \n|         \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|        | \n|         \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|        |-- \n|         \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|         \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|        | \n|         \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|        | \n|       |  \n|");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|        | \n|       | | \n|");

    ArrayDin ArrayBlank;
    ArrayBlank = MakeArrayDin();
    int i = 0;
    int ctr = 0;
    while (tebakan[i] != '\0') {
        InsertLast(&ArrayBlank, "_ ");
        i++;
    }
    ctr = i;

    int salah = 0;
    int benar = 0;
    int score = 100;

    printf("Kata yang harus ditebak:\n");
    PrintArrayDin(ArrayBlank);
    printf("%s\n\n", Get(ArrayHangman, salah));
    while ((salah < 8) && (benar < ctr)) {
        STARTINPUTKATA();
        if (currentWord.Length != 1) {
            printf("Maaf, Anda hanya diperbolehkan untuk memasukkan 1 huruf saja.\n");
        } else {
            char* huruf = WordToString(currentWord);
            capsLock(huruf);
            if (IsInWord(huruf, tertebak)) {
                for (int i = 0;i<ctr;i++) {
                    if (huruf[0] == tebakan[i]) {
                        Set(&ArrayBlank, i, huruf);
                        tertebak.TabWord[i] = '$';
                        benar++;
                    }
                }
                printf("\nYey! Kamu benar! :D\n");
            } else if ((!IsInWord(huruf, tertebak)) && IsInWord(huruf, tebakan1)) {
                printf("\nHuruf sudah ditebak.\n");
            } else if (!IsInWord(huruf, tertebak)) {
                salah++;
                printf("\nYahh, kamu salah :(\n");
                printf("Sisa kesempatan menebak: %d\n", (8-salah));
            }
        }
        printf("\nKata yang harus ditebak:\n");
        PrintArrayDin(ArrayBlank);
        printf("%s\n\n", Get(ArrayHangman, salah));
    }
    score=score-(salah*salah);
    if (salah == 8) {
        score = 0;
        printf("Kata yang benar adalah %s\n", tebakan);
    }
    printf("Kamu memperoleh score sebesar: %d poin!\n", score);
}