#include "TowerOfHanoi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printTower(Stack tiangA, Stack tiangB, Stack tiangC, int n)
{
    Stack newTiangA = tiangA;
    Stack newTiangB = tiangB;
    Stack newTiangC = tiangC;
    infotypeStack newTopStack;
    for (int i = n - 1; i >= 0; i--)
    {
        // Tiang A
        if (IsEmptyStack(tiangA))
        {
            for (int j = 0; j < n - 2; j++)
            {
                printf(" ");
            }
            printf(" | ");
            for (int j = 0; j < n - 2; j++)
            {
                printf(" ");
            }
        }
        else
        {
            // print spaces
            if (TopStack(tiangA) < n - 1)
            {
                if (n == 1)
                {
                    printf("  ");
                }
                else if (n == 2)
                {
                    printf(" ");
                }
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                printf("|");
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                TopStack(tiangA)++;
            }
            else
            {
                if (n == 1)
                {
                    printf("  ");
                }
                else if (n == 2)
                {
                    printf(" ");
                }
                PopStack(&newTiangA, &newTopStack);
                for (int j = 0; j < n - newTopStack; j++)
                {
                    printf(" ");
                }
                for (int j = 0; j < 2 * newTopStack - 1; j++)
                {
                    printf("*");
                }
                // print spaces
                for (int j = 0; j < n - newTopStack; j++)
                {
                    printf(" ");
                }
            }
        }
        printf("\t");

        // Tiang B
        if (IsEmptyStack(tiangB))
        {
            for (int j = 0; j < n - 2; j++)
            {
                printf(" ");
            }
            printf(" | ");
            for (int j = 0; j < n - 2; j++)
            {
                printf(" ");
            }
        }
        else
        {
            if (TopStack(tiangB) < n - 1)
            {
                if (n == 2)
                {
                    printf(" ");
                }
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                printf("|");
                for (int j = 0; j < n - 1; j++)
                {
                    printf(" ");
                }
                TopStack(tiangB)++;
            }
            else
            {
                if (n == 2)
                {
                    printf(" ");
                }
                else if (n == 1)
                {
                    printf("  ");
                }
                PopStack(&newTiangB, &newTopStack);
                for (int j = 0; j < n - newTopStack; j++)
                {
                    printf(" ");
                }
                for (int j = 0; j < 2 * newTopStack - 1; j++)
                {
                    printf("*");
                }
                // print spaces
                for (int j = 0; j < n - newTopStack; j++)
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
            for (int j = 0; j < n - 2; j++)
            {
                printf(" ");
            }
            printf(" | ");
            for (int j = 0; j < n - 2; j++)
            {
                printf(" ");
            }
        }
        else
        {
            if (n == 2)
            {
                printf(" ");
            }
            if (TopStack(tiangC) < n - 1)
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
                TopStack(tiangC)++;
            }
            else
            {
                PopStack(&newTiangC, &newTopStack);
                for (int j = 0; j < n - newTopStack; j++)
                {
                    printf(" ");
                }
                for (int j = 0; j < 2 * newTopStack - 1; j++)
                {
                    printf("*");
                }
                // print spaces
                for (int j = 0; j < n - newTopStack; j++)
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
        if (n == 1 || n == 2)
        {
            printf(" ");
            for (int j = 0; j < 3; j++)
            {
                printf("-");
            }
            printf(" ");
        }
        // print spaces
        else
        {
            printf(" ");
            for (int j = 0; j < 2 * n - 3; j++)
            {
                printf("-");
            }
            // print spaces
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 3; j++)
        {
            printf("-");
        }
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
    }
    printf("\t");

    // tiang B
    if (!IsEmptyStack(tiangB))
    {
        if (n == 1 || n == 2)
        {
            printf(" ");
            for (int j = 0; j < 3; j++)
            {
                printf("-");
            }
            printf(" ");
        }
        else
        {
            printf(" ");
            for (int j = 0; j < 2 * n - 3; j++)
            {
                printf("-");
            }
            // print spaces
            printf(" ");
        }
        // print spaces
    }
    else
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 3; j++)
        {
            printf("-");
        }
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
    }
    printf("\t");

    // tiang C
    if (!IsEmptyStack(tiangC))
    {
        if (n == 1 || n == 2)
        {
            printf(" ");
            for (int j = 0; j < 3; j++)
            {
                printf("-");
            }
            printf(" ");
        }
        else
        {
            printf(" ");
            for (int j = 0; j < 2 * n - 3; j++)
            {
                printf("-");
            }
            // print spaces
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 3; j++)
        {
            printf("-");
        }
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
    }
    printf("\n");

    // huruf A
    if (!IsEmptyStack(tiangA))
    {
        if (n == 1)
        {
            printf("  ");
        }
        else if (n == 2)
        {
            printf(" ");
        }
        for (int j = 0; j < (n - 1); j++)
        {
            printf(" ");
        }
        printf("A");
        for (int j = 0; j < (n - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        printf(" A ");
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
    }
    printf("\t");

    // huruf B
    if (!IsEmptyStack(tiangB))
    {
        if (n == 2)
        {
            printf(" ");
        }
        else if (n == 1)
        {
            printf("  ");
        }
        for (int j = 0; j < (n - 1); j++)
        {
            printf(" ");
        }
        printf("B");
        for (int j = 0; j < (n - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        printf(" B ");
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
    }
    printf("\t");

    // huruf C
    if (!IsEmptyStack(tiangC))
    {
        if (n == 2)
        {
            printf(" ");
        }
        for (int j = 0; j < (n - 1); j++)
        {
            printf(" ");
        }
        printf("C");
        for (int j = 0; j < (n - 1); j++)
        {
            printf(" ");
        }
    }
    else
    {
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        printf(" C ");
        for (int j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
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
    return TopStack(S) == n - 1;
}
void moveDisc(Stack *tiangAwal, Stack *tiangTujuan, int *move)
{
    int disc;

    if (IsEmptyStack(*tiangAwal))
    {
        printf("Tower awal kosong\n");
    }

    else if (InfoTopStack(*tiangAwal) > InfoTopStack(*tiangTujuan))
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
int WordToIntStack(Word W)
{
    int res = 0;
    for (int i = 0; i < W.Length; i++)
    {
        if (W.TabWord[i] >= 48 && W.TabWord[i] <= 57)
        {
            res = res * 10 + (W.TabWord[i] - 48);
        }
        else
        {
            res = -1;
            break;
        }
    }
    return res;
}
void TowerOfHanoi(int *score)
{
    int n;
    printf("\nSelamat datang di Tower Of Hanoi!\n");
    printf("\n");
    printf("Masukkan jumlah disk yang ingin dimainkan: ");
    STARTINPUTKATA();
    n = WordToIntStack(currentWord);
    while (n > 30 || n < 2)
    {
        printf("Jumlah disk tidak boleh lebih dari 30 dan harus lebih besar dari 0\n");
        printf("Masukkan jumlah disk yang ingin dimainkan: ");
        STARTINPUTKATA();
        n = WordToIntStack(currentWord);
    }
    long long int minMove = pow(2, n) - 1;
    long long int currentScore = minMove / 3;
    if (n == 2 || n == 1)
    {
        currentScore = 1;
    }
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
    printf("6. Setiap disk yang dipindahkan akan dihitung sebagai 1 langkah\n");
    printf("7. Akan disediakan minimum move yang perlu dilakukan untuk menyelesaikan permainan ini\n");
    printf("8. Setiap langkap yang melebihi minimum move akan mengurangi score anda sebanyak 1\n");
    printf("9. Minimum Move yang ada bergantung pada jumlah disk yang dimainkan\n");
    printf("10. Jika anda menyerah, maka skor yang didapat adalah 0\n");
    printf("11. Jika anda menyelesaikan permainan, maka skor yang didapat adalah 1/3 dari langkah minimum yang dibutuhkan\n");

    printf("\n");

    int move = 0;
    Word tiangAwal, tiangTujuan;
    boolean gameDone = false;
    printf("your current score: %d\n", currentScore);
    printf("The minimum move you have to make: %d\n\n", minMove);
    while (!IsEqual(tiangTujuan, "EXIT") && !gameDone)
    {
        printf("TURN %d\n", move + 1);
        printf("\n");
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
            printf("Memindahkan piringan ke B...\n\n");
            moveDisc(&TowerA, &TowerB, &move);
        }

        else if (IsEqual(tiangAwal, "A") && IsEqual(tiangTujuan, "C"))
        {
            printf("Memindahkan piringan ke C...\n\n");
            moveDisc(&TowerA, &TowerC, &move);
        }

        else if (IsEqual(tiangAwal, "B") && IsEqual(tiangTujuan, "C"))
        {
            printf("Memindahkan piringan ke C...\n\n");
            moveDisc(&TowerB, &TowerC, &move);
        }

        else if (IsEqual(tiangAwal, "B") && IsEqual(tiangTujuan, "A"))
        {
            printf("Memindahkan piringan ke A...\n\n");
            moveDisc(&TowerB, &TowerA, &move);
        }

        else if (IsEqual(tiangAwal, "C") && IsEqual(tiangTujuan, "A"))
        {
            printf("Memindahkan piringan ke A...\n\n");
            moveDisc(&TowerC, &TowerA, &move);
        }

        else if (IsEqual(tiangAwal, "C") && IsEqual(tiangTujuan, "B"))
        {
            printf("Memindahkan piringan ke B...\n\n");
            moveDisc(&TowerC, &TowerB, &move);
        }

        if (move == minMove)
        {
            printf("Anda memiliki sisa %d langkah\n", currentScore);
        }

        if (move > minMove)
        {
            currentScore--;
            printf("Anda memiliki sisa %d langkah\n", currentScore);
        }

        if (currentScore == 0)
        {
            printf("Kamu kalah!\n");
            gameDone = true;
        }

        if (IsEqual(tiangTujuan, "EXIT"))
        {
            printf("Kamu menyerah!\n");
            currentScore = 0;
            gameDone = true;
        }

        if (IsFullTower(TowerC, n) && IsEmptyStack(TowerA) && IsEmptyStack(TowerB) && !gameDone)
        {
            printf("Selamat! Anda berhasil menyelesaikan permainan ini!\n");
            gameDone = true;
        }
    }
    printf("Score kamu adalah %d\n", currentScore);
    *score = currentScore;
}
