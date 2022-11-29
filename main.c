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
#include "./src/games/SnakeOfMeteor/snakeofmeteor.h"
#include "./src/games/TowerOfHanoi/TowerOfHanoi.h"

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
    Stackchar History;
    ListMap Scoreboard;
    Map Temp;
    MakeArrayOfGame(&ListGame);
    CreateEmptyStackChar(&History);
    createListMap(&Scoreboard);
    CreateEmptyMap(&Temp);
    Queue QueueGame;
    CreateQueue(&QueueGame);
    boolean cek = false;
    int score;
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
                p = fopen(newfile, "r");
                if (p == NULL)
                {
                    printf("Masukkan file dengan benar\n");
                }
                else
                {
                    load(WordToString(x), &ListGame, &History, &Scoreboard);
                    cek = true;
                    fclose(p);
                }
            }
        }
        else if (IsEqual(currentWord, "START"))
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
                createGame(&ListGame, &Scoreboard, &Temp);
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
                playGame(ListGame, &QueueGame, &History, &Scoreboard);
            }
            else if ((IsEqual(takeword(currentWord, 1), "SKIP")) && (IsEqual(takeword(currentWord, 2), "GAME")))
            {
                skipGame(WordToInt(takeword(currentWord, 3)), ListGame, &QueueGame, &History, &Scoreboard);
                if (!isEmpty(QueueGame))
                {
                    if (takeword(currentWord, 3).Length == 0)
                    {
                        printf("Tolong masukkan nomor game yang ingin di skip dengan format 'SKIP GAME <n>'!\n");
                    }
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
                    save(WordToString(x), ListGame, History, Scoreboard);
                }
            }
            else if (IsEqual(currentWord, "SCOREBOARD"))
            {
                scoreboard(Scoreboard, ListGame);
            }
            else if (IsEqual(currentWord, "RESET SCOREBOARD"))
            {
                resetScoreboard(&Scoreboard, &ListGame);
            }
            else if (IsEqual(takeword(currentWord, 1), "HISTORY"))
            {
                history(WordToInt(takeword(currentWord, 2)), History);
                if (!isEmpty(QueueGame))
                {
                    if (takeword(currentWord, 3).Length == 0)
                    {
                        printf("Tolong masukkan jumlah history game yang ingin ditampilkan dengan format 'HISTORY <n>'!\n");
                    }
                }
            }
            else if (IsEqual(currentWord, "RESET HISTORY"))
            {
                resetHistory(&History);
            }
            else if (IsEqual(currentWord, "QUIT"))
            {
                quit(ListGame, History, Scoreboard);
            }
            else
            {
                otherCommand();
            }
        }
    }
    return 0;
}
