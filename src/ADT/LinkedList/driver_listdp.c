#include <stdio.h>
#include "listdp.h"

int main(){
    //Konstruktor
    List L;
    printf("Buat List kosong\n");
    CreateEmpty(&L);
    printf("Is Empty = %d\n", IsEmpty(L));
    
    //Alokasi 
    POINT Y = MakePOINT(1,2);
    address P = Alokasi("3", Y);
    printf("%s\n", Info(P));
    Dealokasi(P);
    printf("%s\n", Info(P));

    //Insert To List
    InsVLast(&L,"1",Y);
    Y = MakePOINT(1,3);
    InsVLast(&L,"2",Y);
    Y = MakePOINT(1,5);
    InsVLast(&L,"3",Y);
    Y = MakePOINT(1,6);
    InsVLast(&L,"4",Y);
    Y = MakePOINT(1,9);
    InsVLast(&L,"5",Y);
    PrintForward(L);
    PrintBackward(L);

    //Search List
    POINT T = MakePOINT(1,5);
    address Q = Search(L,T);
    printf("%s\n", Info(Q));

    //Delete
    DelP(&L,T);
    PrintForward(L);
    DelFirst(&L,&P);
    PrintForward(L);
    DelLast(&L,&P);
    PrintForward(L);

    Dealokasi(P);
    Dealokasi(Q);
}