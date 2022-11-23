#include "TowerOfHanoi.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void printStack(Stack tiangA, Stack tiangB, Stack tiangC, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        // Tiang A
        if (tiangA.T[i] == Nil)
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
            // print spaces
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
        printf("\t");

        // Tiang B
        if (tiangB.T[i] == Nil)
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
            // print spaces
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
        printf("\t");

        // Tiang C
        if (tiangC.T[i] == Nil)
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
            // print spaces
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
        printf("\n");
    }

    // print base
    // tiang A
    if (tiangA.T[0] != Nil)
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
    if (tiangB.T[0] != Nil)
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
    if (tiangC.T[0] != Nil)
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
    if (tiangA.T[0] != Nil)
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
    if (tiangB.T[0] != Nil)
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
    if (tiangC.T[0] != Nil)
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

void TowerOfHanoi(int *score)
{
    int n;
    printf("\nSelamat datang di Tower Of Hanoi!\n");
    printf("\n");
    printf("Masukkan jumlah disk yang ingin dimainkan: ");
    STARTINPUTKATA();
    n = WordToInt(currentWord);
    printf("Anda memilih %d disk\n", n);
    printf("\n");

    Stack TiangA, TiangB, TiangC;
    CreateEmptyStack(&TiangA);
    CreateEmptyStack(&TiangB);
    CreateEmptyStack(&TiangC);

    for (int i = n - 1; i >= 0; i--)
    {
        PushStack(&TiangA, i + 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        PushStack(&TiangB, Nil);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        PushStack(&TiangC, Nil);
    }

    printf("Untuk memainkan permainan ini, silahkan ikuti instruksi berikut:\n");
    printf("1. Masukkan nama tiang awal dari disk yang ingin dipindahkan (A/B/C) pada bagian 'Tiang Asal'\n");
    printf("2. Masukkan nama tiang tujuan dari disk yang ingin dipindahkan (A/B/C) pada bagian 'Tiang Tujuan'\n");
    printf("3. Nama tiang awal dan tiang tujuan tidak boleh sama\n");
    printf("4. Disk hanya dapat dipindahkan ke tiang yang memiliki disk teratas yang lebih besar dari disk yang dipindahkan\n");
    printf("5. Ketik 'EXIT' pada 'tiang tujuan' untuk keluar dari permainan atau saat anda telah menyerah\n");

    int move = 0;
    Word tiangAwal, tiangTujuan;
    while (!IsEqual(tiangTujuan, "EXIT"))
    {
        printf("\n");
        printStack(TiangA, TiangB, TiangC, n);
        printf("\n");
        printf("Tiang Asal: ");
        STARTINPUTKATA();
        tiangAwal = currentWord;
        printf("Tiang Tujuan: ");
        STARTINPUTKATA();
        tiangTujuan = currentWord;

        while (!IsEqual(tiangAwal, "A") && !IsEqual(tiangAwal, "B") && !IsEqual(tiangAwal, "C"))
        {
            printf("Tiang Asal tidak valid!\n");
            printf("Tiang Asal: ");
            STARTINPUTKATA();
            tiangAwal = currentWord;
            printf("Tiang Tujuan: ");
            STARTINPUTKATA();
            tiangTujuan = currentWord;
        }

        while (!IsEqual(tiangTujuan, "A") && !IsEqual(tiangTujuan, "B") && !IsEqual(tiangTujuan, "C") && !IsEqual(tiangTujuan, "EXIT"))
        {
            printf("Tiang Tujuan tidak valid!\n");
            printf("Tiang Asal: ");
            STARTINPUTKATA();
            tiangAwal = currentWord;
            printf("Tiang Tujuan: ");
            STARTINPUTKATA();
            tiangTujuan = currentWord;
        }
        while (IsEqual(tiangAwal, WordToString(tiangTujuan)))
        {
            printf("Tiang Asal dan Tiang Tujuan tidak boleh sama!\n");
            printf("Tiang Asal: ");
            STARTINPUTKATA();
            tiangAwal = currentWord;
            printf("Tiang Tujuan: ");
            STARTINPUTKATA();
            tiangTujuan = currentWord;
        }
    }
}

int main()
{
    int score = 0;
    TowerOfHanoi(&score);
    printf("Score: %d\n", score);
    return 0;
}
