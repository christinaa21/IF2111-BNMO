#include <stdio.h>
#include "hangman.h"

void capsLock(char *huruf)
{
    int i = 0;
    while (huruf[i] != '\0') {
        if ((huruf[i] >= 97) && (huruf[i] <= 122))
        {
            huruf[i] -= 32;
        }
        i++;
    }
}
/* Membuat semua huruf menjadi uppercase */

void lowerCase(char *huruf)
{
    int i = 0;
    while (huruf[i] != '\0') {
        if ((huruf[i] >= 65) && (huruf[i] <= 90))
        {
            huruf[i] += 32;
        }
        i++;
    }
}
/* Membuat semua huruf menjadi uppercase */

void hangMan()
{
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
    InsertLast(&ArrayKata, "ITB");
    InsertLast(&ArrayKata, "STI");
    InsertLast(&ArrayKata, "IF");
    InsertLast(&ArrayKata, "HMIF");
    InsertLast(&ArrayKata, "STEI");
    InsertLast(&ArrayKata, "MULTIMEDIA");
    InsertLast(&ArrayKata, "LABTEK");
    InsertLast(&ArrayKata, "LABDAS");
    InsertLast(&ArrayKata, "ASISTENSI");
    InsertLast(&ArrayKata, "HOLOBIT");

    ArrayDin ArrayHangman;
    ArrayHangman = MakeArrayDin();
    InsertLast(&ArrayHangman, "\n\n\n\n\n\n___");
    InsertLast(&ArrayHangman, "\n|         \n|         \n|         \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|         \n|         \n|         \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|         \n|         \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|         \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|        | \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|        |-- \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|         \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|        | \n|         \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|        | \n|       |  \n|___");
    InsertLast(&ArrayHangman, "_________\n|        | \n|        O \n|      --|-- \n|        | \n|       | | \n|___");

    int salah = 0;
    int score = 0;
    char *huruf;
    char* tebakan;
    char* katasudah;
    int X, i, ctr, benar, gambar;
    Word tertebak;
    Word tebakan1;
    ArrayDin ArrayBlank;

    printf("Hangman telah dimulai! Yuk kita menebak kata!\nDi game ini, kamu harus menebak kata yang berhubungan dengan kehidupan kuliah kita nih!\nBisa saja nama matkul, nama tempat, atau mungkin hal-hal yang kita kerjakan.\n");
    while (salah < 10)
    {
        srand(time(NULL));
        X = rand() % 25;
        tebakan = GetArrayDin(ArrayKata, X);
        tertebak = StringtoWord(tebakan);
        tebakan1 = StringtoWord(tebakan);

        ArrayBlank = MakeArrayDin();
        i = 0;
        ctr = 0;
        while (tebakan[i] != '\0')
        {
            InsertLast(&ArrayBlank, "_ ");
            i++;
        }
        ctr = i;

        Word LetterHistory;
        LetterHistory.Length = 0;
        LetterHistory.TabWord[0] = '-';

        benar = 0;
        gambar = 0;

        while ((salah < 10) && (benar < ctr)) {
            if (LetterHistory.Length == 0) {
                printf("\nTebakan sebelumnya: %c\n", LetterHistory.TabWord[0]);
            } else {
                katasudah = WordToString(LetterHistory);
                lowerCase(katasudah);
                printf("\nTebakan sebelumnya: %s\n", katasudah);
            }
            printf("Kata: ");
            PrintArrayDin(ArrayBlank);
            printf("%s\n", GetArrayDin(ArrayHangman, gambar));
            printf("Kesempatan: %d\n", (10 - salah));
            printf("Masukkan tebakan: ");
            STARTINPUTKATA();
            if (currentWord.Length != 1)
            {
                printf("Maaf, Anda hanya diperbolehkan untuk memasukkan 1 huruf saja.\n");
            }
            else
            {
                huruf = WordToString(currentWord);
                capsLock(huruf);
                if (IsInWord(huruf, tertebak))
                {
                    for (i = 0; i < ctr; i++)
                    {
                        if (huruf[0] == tebakan[i])
                        {
                            SetArrayDin(&ArrayBlank, i, huruf);
                            tertebak.TabWord[i] = '$';
                            benar++;
                        }
                    }
                    LetterHistory.TabWord[LetterHistory.Length] = huruf[0];
                    LetterHistory.Length++;
                    printf("\n******* Yey! Kamu benar! :D *******\n");
                }
                else
                {
                    if (IsInWord(huruf, LetterHistory)) {
                        printf("\n******* Huruf sudah ditebak. *******\n");
                    }
                    else
                    {
                        LetterHistory.TabWord[LetterHistory.Length] = huruf[0];
                        LetterHistory.Length++;
                        salah++;
                        gambar++;
                        printf("\n******* Yahh, kamu salah :( *******\n");
                    }
                }
            }
        }
        if (benar == ctr) {
            printf("\n--- Berhasil menebak kata %s! Kamu mendapatkan %d poin! ---\n", tebakan, benar);
        }
        score += benar;
        DeallocateArrayDin(&ArrayBlank);
    }
    printf("%s\n", GetArrayDin(ArrayHangman, gambar));
    printf("Kesempatan: %d\n", (10 - salah));
    printf("Kata yang benar adalah %s\n\n", tebakan);
    printf("Kesempatan menebakmu telah habis! Permainan berakhir...\n");
    printf("Kamu memperoleh total poin sebesar: %d poin!\n\n", score);
    printf("--- GAME OVER ---\n");
    
    DeallocateArrayDin(&ArrayHangman);
    DeallocateArrayDin(&ArrayKata);
}

int main() {
    hangMan();
    return 0;
}