#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "./src/game_util/game_util.h"
#include "./src/games/diner_dash/diner_dash.h"
#include "./src/games/random_number_generator/random_number_generator.h"
#include "./src/games/game_tambahan/game_tambahan.h"
#include "./src/games/hangman/hangman.h"
#include "./src/games/TicTacToe/tictactoe.h"
#include "./src/main_util/main_util.h"

void displaybinomo()
{
    printf(" _______   ______  __    __   ______   __       __   ______\n");
    printf("/       \\ /      |/  \\  /  | /      \\ /  \\     /  | /      \\\n");
    printf("$$$$$$$  |$$$$$$/ $$  \\ $$ |/$$$$$$  |$$  \\   /$$ |/$$$$$$  |\n");
    printf("$$ |__$$ |  $$ |  $$$  \\$$ |$$ |  $$ |$$$  \\ /$$$ |$$ |  $$ |\n");
    printf("$$    $$<   $$ |  $$$$  $$ |$$ |  $$ |$$$$  /$$$$ |$$ |  $$ | \n");
    printf("$$ |__$$ | _$$ |_ $$ |$$$$ |$$ \\__$$ |$$ |$$$/ $$ |$$ \\__$$ |\n");
    printf("$$    $$/ / $$   |$$ | $$$ |$$    $$/ $$ | $/  $$ |$$    $$/ \n");
    printf("$$$$$$$/  $$$$$$/ $$/   $$/  $$$$$$/  $$/      $$/  $$$$$$/  \n");
}

int main()
{
    displaybinomo();
    printf("\n");
    ArrayOfGame ListGame;
    MakeArrayOfGame(&ListGame);
    Queue QueueGame;
    CreateQueue(&QueueGame);
    boolean cek = false;
    while (!cek)
    {
        printf("Masukkan Command (START / LOAD <file_name>): ");
        STARTINPUTKATA();
        if (IsEqual(takeword(currentWord, 1), "LOAD"))
        {
            if (currentWord.Length == 4)
            {
                printf("Tolong masukkan nama file!\n");
            }
            else
            {
                Word x = takeword(currentWord, 2);
                char *path = "Data/";
                char *newfile = ConcateChar(path, WordToString(x));
                FILE *p;
                p = fopen(newfile,"r");
                if (p == NULL){
                    printf("Masukkan file dengan benar\n");
                }
                else {
                    load(WordToString(x), &ListGame);
                    cek = true;
                    fclose(p);
                }
            }
        }
        else if (IsEqual(takeword(currentWord, 1), "START"))
        {
            printf("Selamat datang di Binomo!\n");
            start(&ListGame);
            cek = true;
        }
        else
        {
            printf("Masukkan command START atau LOAD di awal permainan\n");
        }
        while (cek)
        {
            printf("\nKetik HELP untuk melihat list command yang dapat digunakan\n");
            printf("Masukkan Command: ");
            STARTINPUTKATA();
            if (IsEqual(currentWord, "CREATE GAME"))
            {
                createGame(&ListGame);
            }
            else if (IsEqual(currentWord, "LIST GAME"))
            {
                listGame(&ListGame);
            }
            else if (IsEqual(currentWord, "DELETE GAME"))
            {
                deleteGame(&ListGame, QueueGame);
            }
            else if (IsEqual(currentWord, "QUEUE GAME"))
            {
                queueGame(&QueueGame, ListGame);
            }
            else if (IsEqual(currentWord, "PLAY GAME"))
            {
                playGame(&QueueGame);
            }
            else if ((IsEqual(takeword(currentWord, 1), "SKIP")) && (IsEqual(takeword(currentWord, 2), "GAME")))
            {
                skipGame(WordToInt(takeword(currentWord, 3)), &QueueGame);
                if (takeword(currentWord, 2).Length == 0)
                {
                    printf("Tolong masukkan nomor game yang ingin di skip dengan format 'SKIPGAME <n>'!\n");
                }
            }
            else if (IsEqual(currentWord, "HELP"))
            {
                help();
            }
            else if (IsEqual(takeword(currentWord, 1), "SAVE"))
            {
                if (currentWord.Length == 4)
                {
                    printf("Tolong masukkan nama file!\n");
                }
                else
                {
                    Word x = takeword(currentWord, 2);
                    save(WordToString(x), ListGame);
                }
            }
            else if (IsEqual(currentWord, "QUIT"))
            {
                quit(ListGame);
            }
            else
            {
                otherCommand();
            }
        }
    }
    return 0;
}
