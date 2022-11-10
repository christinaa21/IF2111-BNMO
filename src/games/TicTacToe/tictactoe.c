#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void board(ArrayOfGame arr)
{

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", GetGame(arr, 0).TabWord[0], GetGame(arr, 1).TabWord[0], GetGame(arr, 2).TabWord[0]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", GetGame(arr, 3).TabWord[0], GetGame(arr, 4).TabWord[0], GetGame(arr, 5).TabWord[0]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", GetGame(arr, 6).TabWord[0], GetGame(arr, 7).TabWord[0], GetGame(arr, 8).TabWord[0]);

    printf("     |     |     \n\n");
}

int cekwin(ArrayOfGame arr)
{
    int win = 0;
    if (GetGame(arr, 0).TabWord[0] == GetGame(arr, 1).TabWord[0] && GetGame(arr, 0).TabWord[0] == GetGame(arr, 2).TabWord[0])
    {
        if (GetGame(arr, 0).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 0).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 3).TabWord[0] == GetGame(arr, 4).TabWord[0] && GetGame(arr, 3).TabWord[0] == GetGame(arr, 5).TabWord[0])
    {
        if (GetGame(arr, 3).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 3).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 6).TabWord[0] == GetGame(arr, 7).TabWord[0] && GetGame(arr, 6).TabWord[0] == GetGame(arr, 8).TabWord[0])
    {
        if (GetGame(arr, 6).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 6).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 0).TabWord[0] == GetGame(arr, 3).TabWord[0] && GetGame(arr, 0).TabWord[0] == GetGame(arr, 6).TabWord[0])
    {
        if (GetGame(arr, 3).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 3).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 1).TabWord[0] == GetGame(arr, 4).TabWord[0] && GetGame(arr, 1).TabWord[0] == GetGame(arr, 7).TabWord[0])
    {
        if (GetGame(arr, 1).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 1).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 2).TabWord[0] == GetGame(arr, 5).TabWord[0] && GetGame(arr, 2).TabWord[0] == GetGame(arr, 8).TabWord[0])
    {
        if (GetGame(arr, 2).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 2).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 0).TabWord[0] == GetGame(arr, 4).TabWord[0] && GetGame(arr, 0).TabWord[0] == GetGame(arr, 8).TabWord[0])
    {
        if (GetGame(arr, 0).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 0).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    else if (GetGame(arr, 2).TabWord[0] == GetGame(arr, 4).TabWord[0] && GetGame(arr, 2).TabWord[0] == GetGame(arr, 6).TabWord[0])
    {
        if (GetGame(arr, 2).TabWord[0] == 'X')
        {
            win = 2;
        }
        else if (GetGame(arr, 2).TabWord[0] == 'O')
        {
            win = 1;
        }
    }
    return win;
}

void tictactoe()
{
    printf("\n\n======== WELCOME TO TIC TAC TOE ========\n\n");
    ArrayOfGame TBoard = MakeArrayOfGame();
    int i;
    Word set;
    for (i = 0; i < 9; i++)
    {
        set.Length = 1;
        set.TabWord[0] = (i + 1) + '0';
        InsertGameAt(&TBoard, set, i);
    }
    int count = 0;
    int won = cekwin(TBoard);
    printf("Anda : 'O' || Com : 'X'\n\n");
    srand(time(NULL));
    while (won == 0 && count < 9)
    {
        if (count % 2 == 0)
        {
            board(TBoard);
            printf("Masukkan nomor kotak: ");
            STARTINPUTKATA();
            if (WordToInt(currentWord) > 9 || WordToInt(currentWord) < 1)
            {
                printf("Masukkan nomor kotak dengan benar\n");
            }
            else
            {
                if (GetGame(TBoard, WordToInt(currentWord) - 1).TabWord[0] == 'O' || GetGame(TBoard, WordToInt(currentWord) - 1).TabWord[0] == 'X')
                {
                    printf("Kotak sudah terisi silahkan pilih kotak lain\n");
                }
                else
                {
                    TBoard.A[WordToInt(currentWord) - 1].TabWord[0] = 'O';
                    count++;
                    won = cekwin(TBoard);
                }
            }
        }
        else
        {
            int c = (rand() % 9) + 1;
            if (c >= 1 && c <= 9)
            {
                if (GetGame(TBoard, c - 1).TabWord[0] != 'O' && GetGame(TBoard, c - 1).TabWord[0] != 'X')
                {
                    TBoard.A[c - 1].TabWord[0] = 'X';
                    count++;
                    won = cekwin(TBoard);
                }
            }
        }
    }
    board(TBoard);
    if (won == 0)
    {
        printf("=====Tidak ada yang menang=====\n");
    }
    else if (won == 1)
    {
        printf("=====Selamat Anda menang=====\n");
    }
    else if (won == 2)
    {
        printf("=====Yahhh Anda kalah=====\n");
    }
}