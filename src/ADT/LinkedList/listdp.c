#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsEmptyListdp(Listdp L){
    return (First(L) == NilListdp && Last(L) == NilListdp);
}

void CreateEmptyListdp(Listdp *L){
    First(*L) = NilListdp;
    Last(*L) = NilListdp;
}
addressListdp AlokasiListdp(infotypeListdp X, POINT Y){
    addressListdp P = (addressListdp) malloc (sizeof(ElmtListdp));
    if (P!=NilListdp){
        Info(P) = X;
        Next(P) = NilListdp;
        Prev(P) = NilListdp;
        Pos(P) = Y;
    }
    return P;
}

void DealokasiListdp(addressListdp P){
    free(P);
}

addressListdp SearchListdp(Listdp L, POINT Y){
    addressListdp P = First(L);
    boolean ada = false; 
    while (P!=NilListdp && !ada){
        if(Pos(P).x == Y.x && Pos(P).y == Y.y){
            ada = true;
        }
        else{
            P = Next(P);
        }
    }
    if (ada){
        return P;
    }
    else {
        return NilListdp;
    }
}

void InsVLastListdp(Listdp *L, infotypeListdp X, POINT Y){
    addressListdp P = AlokasiListdp(X,Y);
    if (P!=NilListdp){
        if(!IsEmptyListdp(*L)){
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;           
        }
        else{
            First(*L) = P;
            Last(*L) = P;
        }
    }
}

void DelFirstListdp(Listdp *L, addressListdp *P){
    *P = First(*L);
    if (Next(*P) == NilListdp){
        First(*L) = NilListdp;
        Last(*L) = NilListdp;
    }
    else {
        First(*L) = Next(*P);
        Prev(Next(*P)) = NilListdp;
    }
}

void DelLastListdp(Listdp *L, addressListdp *P){
    *P = Last(*L);
    if(Prev(*P) == NilListdp){
        First(*L) = NilListdp;
        Last(*L) = NilListdp;
    }
    else {
        Last(*L) = Prev(*P);
        Next(Prev(*P)) = NilListdp;
    }
}


void DelPListdp(Listdp *L, POINT X){
    addressListdp P = SearchListdp(*L,X);
    if (P!=NilListdp){
        if (Prev(P) == NilListdp){
            DelFirstListdp(L,&P);
        }
        else if (Next(P) == NilListdp){
            DelLastListdp(L,&P);
        }
        else {
            addressListdp Q = Last(*L);
            addressListdp R;
            while(Q != P){
                R = Prev(Q);
                Info(Q) = Info(R);
                Q = Prev(Q);
            }
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
        DealokasiListdp(P);
    }
}

void PrintForwardListdp(Listdp L){
    addressListdp P = First(L);
    if (IsEmptyListdp(L)){
        printf("[]");
    }
    else {
        printf("[");
        while(P!=NilListdp){
            if(P!=Last(L)){
                printf("%s,",Info(P));
            }
            else {
                printf("%s", Info(P));
            }
            P = Next(P);
        }
        printf("]");
    }
}

void PrintBackwardListdp(Listdp L){
    addressListdp P = Last(L);
    if (IsEmptyListdp(L)){
        printf("[]");
    }
    else {
        printf("[");
        while(P!=NilListdp){
            if(P!=First(L)){
                printf("%s,",Info(P));
            }
            else {
                printf("%s", Info(P));
            }
            P = Prev(P);
        }
        printf("]");
    }
}

POINT GetLastPosListdp(Listdp L){
    return Pos(Last(L));
}


