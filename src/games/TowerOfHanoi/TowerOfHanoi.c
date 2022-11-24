#include "TowerOfHanoi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printTower(Stack tiangA, Stack tiangB, Stack tiangC, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        // Tiang A
        if (IsEmptyStack(tiangA))
        {
            printf(" | ");
        }
        else
        {
            // print spaces
            if (Top(tiangA) < n - 1)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                printf("|");
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                Top(tiangA)++;
            }
            else
            {
                for (int j = 0; j < n - tiangA.T[i]; j++)
                {
                    printf(" ");
                }
                for (int j = 0; j < 2 * tiangA.T[i] - 1; j++)
                {
                    printf("*");
                }
                // print spaces
                for (int j = 0; j < n - tiangA.T[i]; j++)
                {
                    printf(" ");
                }
            }
        }
        printf("\t");

        // Tiang B
        if (IsEmptyStack(tiangB))
        {
            printf(" | ");
        }
        else
        {
            if (Top(tiangB) < n - 1)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                printf("|");
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                Top(tiangB)++;
            }
            else
            {
                for (int j = 0; j < n - tiangB.T[i]; j++)
                {
                    printf(" ");
                }
                for (int j = 0; j < 2 * tiangB.T[i] - 1; j++)
                {
                    printf("*");
                }
                // print spaces
                for (int j = 0; j < n - tiangB.T[i]; j++)
                {
                    printf(" ");
                }
            }
        }
        printf("\t");

        // Tiang C
        if (IsEmptyStack(tiangC))
        {
            // print spaces
            for (int j = 0; j < 1; j++)
            {
                printf(" ");
            }
            printf("|");
        }
        else
        {
            if (Top(tiangC) < n - 1)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                printf("|");
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                Top(tiangC)++;
            }
            else
            {
                for (int j = 0; j < n - tiangC.T[i]; j++)
                {
                    printf(" ");
                }
                for (int j = 0; j < 2 * tiangC.T[i] - 1; j++)
                {
                    printf("*");
                }
                // print spaces
                for (int j = 0; j < n - tiangC.T[i]; j++)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    // print base
    // tiang A
    if (!IsEmptyStack(tiangA))
    {
        // print spaces
        for (int j = 0; j < n - (tiangA.T[0] - 1); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * tiangA.T[0] - 3; j++)
        {
            printf("-");
        }
        // print spaces
        for (int j = 0; j < n - (tiangA.T[0] - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            printf("-");
        }
    }
    printf("\t");

    // tiang B
    if (!IsEmptyStack(tiangB))
    {
        // print spaces
        for (int j = 0; j < n - (tiangB.T[0] - 1); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * tiangB.T[0] - 3; j++)
        {
            printf("-");
        }
        // print spaces
        for (int j = 0; j < n - (tiangB.T[0] - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            printf("-");
        }
    }
    printf("\t");

    // tiang C
    if (!IsEmptyStack(tiangC))
    {
        // print spaces
        for (int j = 0; j < n - (tiangC.T[0] - 1); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * tiangC.T[0] - 3; j++)
        {
            printf("-");
        }
        // print spaces
        for (int j = 0; j < n - (tiangC.T[0] - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            printf("-");
        }
    }
    printf("\n");

    // huruf A
    if (!IsEmptyStack(tiangA))
    {
        for (int j = 0; j < (tiangA.T[0] - 1); j++)
        {
            printf(" ");
        }
        printf("A");
        for (int j = 0; j < (tiangA.T[0] - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        printf(" A");
    }
    printf("\t");

    // huruf B
    if (!IsEmptyStack(tiangB))
    {
        for (int j = 0; j < (tiangB.T[0] - 1); j++)
        {
            printf(" ");
        }
        printf("B");
        for (int j = 0; j < (tiangB.T[0] - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        printf(" B");
    }
    printf("\t");

    // huruf C
    if (!IsEmptyStack(tiangC))
    {
        for (int j = 0; j < (tiangC.T[0] - 1); j++)
        {
            printf(" ");
        }
        printf("C");
        for (int j = 0; j < (tiangC.T[0] - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        printf(" C");
    }
    printf("\n");
}

void inputTower(Word *tiangAwal, Word *tiangTujuan)
{
    printf("Tiang Asal: ");
    STARTINPUTKATA();
    *tiangAwal = currentWord;
    printf("Tiang Tujuan: ");
    STARTINPUTKATA();
    *tiangTujuan = currentWord;
}

boolean IsFullTower(Stack S, int n)
{
    return Top(S) == n - 1;
}
void moveDisc(Stack *tiangAwal, Stack *tiangTujuan, int *move)
{
    int disc;

    if (IsEmptyStack(*tiangAwal))
    {
        printf("Tower awal kosong\n");
    }

    else if (InfoTop(*tiangAwal) > InfoTop(*tiangTujuan))
    {
        if (IsEmptyStack(*tiangTujuan))
        {
            PopStack(tiangAwal, &disc);
            PushStack(tiangTujuan, disc);
            *move += 1;
        }
        else
        {
            printf("Disc pada Tower tujuan tidak boleh lebih kecil dari Tower awal\n");
        }
    }

    else
    {
        PopStack(tiangAwal, &disc);
        PushStack(tiangTujuan, disc);
        *move += 1;
    }
}
void TowerOfHanoi(int *score)
{
    int n;
    printf("\nSelamat datang di Tower Of Hanoi!\n");
    printf("\n");
    printf("Masukkan jumlah disk yang ingin dimainkan: ");
    STARTINPUTKATA();
    n = WordToInt(currentWord);
    int minMove = pow(2, n) - 1;
    int currentScore = 10;
    printf("Anda memilih %d disk\n", n);
    printf("\n");

    Stack TowerA, TowerB, TowerC;
    CreateEmptyStack(&TowerA);
    CreateEmptyStack(&TowerB);
    CreateEmptyStack(&TowerC);

    for (int i = n - 1; i >= 0; i--)
    {
        PushStack(&TowerA, i + 1);
    }

    printf("Untuk memainkan permainan ini, silahkan ikuti instruksi berikut:\n");
    printf("1. Masukkan nama tiang awal dari disk yang ingin dipindahkan (A/B/C) pada bagian 'Tiang Asal'\n");
    printf("2. Masukkan nama tiang tujuan dari disk yang ingin dipindahkan (A/B/C) pada bagian 'Tiang Tujuan'\n");
    printf("3. Nama tiang awal dan tiang tujuan tidak boleh sama\n");
    printf("4. Disk hanya dapat dipindahkan ke tiang yang memiliki disk teratas yang lebih besar dari disk yang dipindahkan\n");
    printf("5. Ketik 'EXIT' pada 'tiang tujuan' untuk keluar dari permainan atau saat anda telah menyerah\n");

    int move = 0;
    Word tiangAwal, tiangTujuan;
    boolean gameDone = false;
    printf("currentScore: %d\n", currentScore);
    printf("minMove: %d\n", minMove);
    while (!IsEqual(tiangTujuan, "EXIT") && !gameDone)
    {
        printf("\n");
        PrintStack(TowerA);
        PrintStack(TowerB);
        PrintStack(TowerC);
        printTower(TowerA, TowerB, TowerC, n);
        printf("\n");
        inputTower(&tiangAwal, &tiangTujuan);

        while (!IsEqual(tiangAwal, "A") && !IsEqual(tiangAwal, "B") && !IsEqual(tiangAwal, "C"))
        {
            printf("Tiang Asal tidak valid!\n");
            inputTower(&tiangAwal, &tiangTujuan);
        }

        while (!IsEqual(tiangTujuan, "A") && !IsEqual(tiangTujuan, "B") && !IsEqual(tiangTujuan, "C") && !IsEqual(tiangTujuan, "EXIT"))
        {
            printf("Tiang Tujuan tidak valid!\n");
            inputTower(&tiangAwal, &tiangTujuan);
        }
        while (IsEqual(tiangAwal, WordToString(tiangTujuan)))
        {
            printf("Tiang Asal dan Tiang Tujuan tidak boleh sama!\n");
            inputTower(&tiangAwal, &tiangTujuan);
        }

        if (IsEqual(tiangAwal, "A") && IsEqual(tiangTujuan, "B"))
        {
            printf("Memindahkan piringan ke B...\n");
            moveDisc(&TowerA, &TowerB, &move);
        }

        else if (IsEqual(tiangAwal, "A") && IsEqual(tiangTujuan, "C"))
        {
            printf("Memindahkan piringan ke C...\n");
            moveDisc(&TowerA, &TowerC, &move);
        }

        else if (IsEqual(tiangAwal, "B") && IsEqual(tiangTujuan, "C"))
        {
            printf("Memindahkan piringan ke C...\n");
            moveDisc(&TowerB, &TowerC, &move);
        }

        else if (IsEqual(tiangAwal, "B") && IsEqual(tiangTujuan, "A"))
        {
            printf("Memindahkan piringan ke A...\n");
            moveDisc(&TowerB, &TowerA, &move);
        }

        else if (IsEqual(tiangAwal, "C") && IsEqual(tiangTujuan, "A"))
        {
            printf("Memindahkan piringan ke A...\n");
            moveDisc(&TowerC, &TowerA, &move);
        }

        else if (IsEqual(tiangAwal, "C") && IsEqual(tiangTujuan, "B"))
        {
            printf("Memindahkan piringan ke B...\n");
            moveDisc(&TowerC, &TowerB, &move);
        }

        if (move >= minMove)
        {
            printf("Anda memiliki sisa %d langkah\n", currentScore);
            currentScore--;
        }

        if (currentScore == 0)
        {
            printf("Kamu kalah!\n");
            printf("Skor kamu adalah %d\n", currentScore);
            gameDone = true;
        }

        if (IsEqual(tiangTujuan, "EXIT"))
        {
            printf("Kamu menyerah!\n");
            printf("Skor kamu adalah 0\n");
            currentScore = 0;
            gameDone = true;
        }

        if (IsFullTower(TowerC, n) && IsEmptyStack(TowerA) && IsEmptyStack(TowerB))
        {
            printf("Selamat! Anda berhasil menyelesaikan permainan ini!\n");
            printf("Skor kamu adalah %d\n", currentScore);
            gameDone = true;
        }

        printf("currentScore: %d\n", currentScore);
        printf("move: %d\n", move);
    }
    *score = currentScore;
}

int main()
{
    int score = 0;
    TowerOfHanoi(&score);
    printf("Score: %d\n", score);
    return 0;
}
