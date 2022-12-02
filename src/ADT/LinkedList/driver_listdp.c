#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

int main()
{
    // Konstruktor
    Listdp L;
    printf("Buat List kosong\n");
    CreateEmptyListdp(&L);
    printf("Is Empty = %d\n", IsEmptyListdp(L));

    // Alokasi
    POINT Y = MakePOINT(1, 2);
    addressListdp P = AlokasiListdp("3", Y);
    printf("%s\n", Info(P));
    DealokasiListdp(P);

    // Insert To List
    InsVLastListdp(&L, "1", Y);
    Y = MakePOINT(1, 3);
    InsVLastListdp(&L, "2", Y);
    Y = MakePOINT(1, 5);
    InsVLastListdp(&L, "3", Y);
    Y = MakePOINT(1, 6);
    InsVLastListdp(&L, "4", Y);
    Y = MakePOINT(1, 9);
    InsVLastListdp(&L, "5", Y);
    Printf("Print dari depan: ");
    PrintForwardListdp(L);
    printf("\nPrint dari belakang: ");
    PrintBackwardListdp(L);
    printf("\n");

    POINT T = GetLastPosListdp(L);
    printf("Berikut titik di akhir indeks di LinkedList: %d %d\n", T.x, T.y);
    // Search List
    T = MakePOINT(1, 5);
    addressListdp Q = SearchListdp(L, T);
    printf("%s\n", Info(Q));

    // Delete
    DelPListdp(&L, T);
    PrintForwardListdp(L);
    DelFirstListdp(&L, &P);
    PrintForwardListdp(L);
    DelLastListdp(&L, &P);
    PrintForwardListdp(L);

    DealokasiListdp(P);
    DealokasiListdp(Q);
}