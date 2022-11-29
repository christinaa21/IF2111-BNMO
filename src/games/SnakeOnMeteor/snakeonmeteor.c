#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "snakeonmeteor.h"

char* IntToString(int x)
{
    int i, x_copy, digit;
    int len = 0;
    x_copy = x;
    while (x_copy != 0)
    {
        len++;
        x_copy /= 10;
    }
    char* str = malloc(len*sizeof(char));
    while (str == NULL) {
        str = malloc(len*sizeof(char));
    }
    for (i = 0; i < len; i++)
    {
        digit = x % 10;
        x = x / 10;
        str[len - (i + 1)] = digit + '0';
    }
    str[len] = '\0';
    return str;
}

void printmap(Listdp L, POINT M, POINT F, POINT O)
{
    int i, j;
    POINT S;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    printf(" ");
                }
                else
                {
                    printf("---");
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    printf("|");
                }
                else
                {
                    S.x = j / 2;
                    S.y = i / 2;
                    if (SearchListdp(L, S) != NilListdp)
                    {
                        if (M.x == S.x && M.y == S.y)
                        {
                            printf(" m ");
                        }
                        else if (O.x == S.x && O.y == S.y)
                        {
                            printf(" # ");
                        }
                        else
                        {
                            printf(" %s ", SearchListdp(L, S)->info);
                        }
                    }
                    else
                    {
                        if (F.x == S.x && F.y == S.y)
                        {
                            printf(" o ");
                        }
                        else if (M.x == S.x && M.y == S.y)
                        {
                            printf(" m ");
                        }
                        else if (O.x == S.x && O.y == S.y)
                        {
                            printf(" # ");
                        }
                        else
                        {
                            printf("   ");
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}

POINT Obstacle(Listdp L) {
    POINT O;
    srand(time(NULL));
    O.x = rand() % 5;
    O.y = rand() % 5;
    while (SearchListdp(L, O) != NilListdp)
    {
        O.x = rand() % 5;
        O.y = rand() % 5;
    }
    return O;
}

POINT Food(Listdp L, POINT Obstacle)
{
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while ((SearchListdp(L, P) != NilListdp) || (P.x == Obstacle.x && P.y == Obstacle.y))
    {
        P.x = rand() % 5;
        P.y = rand() % 5;
    }
    return P;
}

POINT Meteor(POINT Food, POINT Obstacle)
{
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while ((P.x == Food.x && P.y == Food.y) || (P.x == Obstacle.x && P.y == Obstacle.y))
    {
        P.x = rand() % 5;
        P.y = rand() % 5;
    }
    return P;
}

void UserMove(Listdp L, char input, boolean *illegal_move, POINT Meteor)
{
    addressListdp P = First(L);
    *illegal_move = false;
    POINT Temp;
    if (input == 'w')
    {
        Temp.x = Pos(P).x % 5;
        Temp.y = (Pos(P).y + 4) % 5;
    }
    else if (input == 'a')
    {
        Temp.x = (Pos(P).x + 4) % 5;
        Temp.y = Pos(P).y % 5;
    }
    else if (input == 's')
    {
        Temp.x = Pos(P).x % 5;
        Temp.y = (Pos(P).y + 1) % 5;
    }
    else if (input == 'd')
    {
        Temp.x = (Pos(P).x + 1) % 5;
        Temp.y = Pos(P).y % 5;
    }
    if (SearchListdp(L, Temp) != NilListdp)
    {
        (*illegal_move) = true;
        printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilahkan masukkan command yang lain\n\n");
    }
    else if (Temp.x == Meteor.x && Temp.y == Meteor.y)
    {
        (*illegal_move) = true;
        printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\nSilakan masukkan command yang lain\n\n");
    }
    else
    {
        addressListdp Q;
        P = Last(L);
        while (P != First(L))
        {
            Q = Prev(P);
            Pos(P).x = Pos(Q).x;
            Pos(P).y = Pos(Q).y;
            P = Prev(P);
        }
        Pos(P).x = Temp.x;
        Pos(P).y = Temp.y;
    }
}

void FirstRandSnake(Listdp *L)
{
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    InsVLastListdp(L, "H", P);
    if (P.x >= 2)
    {
        P.x -= 1;
        InsVLastListdp(L, "1", P);
        P.x -= 1;
        InsVLastListdp(L, "2", P);
    }
    else
    {
        if (P.x == 1)
        {
            P.x -= 1;
            InsVLastListdp(L, "1", P);
            if (P.y == 0)
            {
                P.y += 1;
                InsVLastListdp(L, "2", P);
            }
            else
            {
                P.y -= 1;
                InsVLastListdp(L, "2", P);
            }
        }
        else if (P.x == 0)
        {
            if (P.y >= 2)
            {
                P.y -= 1;
                InsVLastListdp(L, "1", P);
                P.y -= 1;
                InsVLastListdp(L, "2", P);
            }
            else
            {
                if (P.y == 1)
                {
                    P.y += 1;
                    InsVLastListdp(L, "1", P);
                    P.y += 1;
                    InsVLastListdp(L, "2", P);
                }
                else
                {
                    P.y += 1;
                    InsVLastListdp(L, "1", P);
                    P.y += 1;
                    InsVLastListdp(L, "2", P);
                }
            }
        }
    }
}

void SnakeOnMeteor(int* score)
{
    Listdp L;
    CreateEmptyListdp(&L);
    FirstRandSnake(&L);
    POINT temp;
    POINT O = Obstacle(L);
    POINT F = Food(L, O);
    POINT M = MakePOINT(5, 5);
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Mengenerate peta, snake, makanan, dan obstacle ...\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan\n");
    printmap(L, M, F, O);
    int idk = 3;
    char* idk_char;
    int turn = 1;
    (*score) = 0;
    char A[] = "a";
    char W[] = "w";
    char S[] = "s";
    char D[] = "d";
    boolean GameOver = false;
    boolean illegal_move = false;
    while (!GameOver)
    {
        do {
            printf("TURN %d:\n", turn);
            printf("Silahkan masukkan command Anda: ");
            STARTINPUTKATA();
            printf("\n");
            while (!IsEqual(currentWord, A) && !IsEqual(currentWord, W) && !IsEqual(currentWord, S) && !IsEqual(currentWord, D))
            {
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                printf("Silahkan masukkan command Anda: ");
                STARTINPUTKATA();
                printf("\n");
            }
            temp = GetLastPosListdp(L);
            UserMove(L, currentWord.TabWord[0], &illegal_move, M);
        } while (illegal_move);
        printf("Berhasil bergerak!\nBerikut merupakan peta permainan\n");

        if (Pos(First(L)).x == F.x && Pos(First(L)).y == F.y)
        {
            idk_char = IntToString(idk);
            InsVLastListdp(&L, idk_char, temp);
            idk++;
            F = Food(L, O);
        }
        M = Meteor(F, O);
        printmap(L, M, F, O);
        if (Pos(First(L)).x == O.x && Pos(First(L)).y == O.y)
        {
            addressListdp p = First(L);
            while (p != NilListdp) {
                (*score)++;
                p = Next(p);
            }
            (*score) *= 2;
            printf("Kepala snake menabrak obstacle!\n");
            GameOver = true;
        }
        if (!GameOver) {
            if (SearchListdp(L, M) != NilListdp)
            {
                if (Pos(First(L)).x == M.x && Pos(First(L)).y == M.y)
                {
                    addressListdp p = First(L);
                    while (p != Last(L)) {
                        (*score)++;
                        p = Next(p);
                    }
                    (*score) *= 2;
                    printf("Kepala snake terkena meteor!\n");
                    GameOver = true;
                } else {
                    DelPListdp(&L, M);
                    idk--;
                    printf("\nAnda terkena meteor!\n");
                    printf("Berikut merupakan peta permainan sekarang:\n");
                    printmap(L, M, F, O);
                    printf("Silakan lanjutkan permainan.\n");
                }
            } else {
                printf("Anda beruntung tidak terkena meteor! Silakan lanjutkan permainan.\n\n");
            }
        }
        turn++;
    }
    printf("Game berakhir. Skor %d\n\n", (*score));
    printf("===== GAME OVER =====\n");
}