#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsEmpty (List L){
    return (First(L) == Nil && Last(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}
address Alokasi (infotype X, POINT Y){
    address P = (address) malloc (sizeof(ElmtList));
    if (P!=Nil){
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
        Pos(P) = Y;
    }
    return P;
}

void Dealokasi (address P){
    free(P);
}

address Search (List L, POINT Y){
    address P = First(L);
    boolean ada = false; 
    while (P!=Nil && !ada){
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
        return Nil;
    }
}

void InsVLast (List *L, infotype X, POINT Y){
    address P = Alokasi(X,Y);
    if (P!=Nil){
        if(!IsEmpty(*L)){
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

void DelFirst (List *L, address *P){
    *P = First(*L);
    if (Next(*P) == Nil){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        First(*L) = Next(*P);
        Prev(Next(*P)) = Nil;
    }
}

void DelLast (List *L, address *P){
    *P = Last(*L);
    if(Prev(*P) == Nil){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        Last(*L) = Prev(*P);
        Next(Prev(*P)) = Nil;
    }
}


void DelP (List *L, POINT X){
    address P = Search(*L,X);
    if (P!=Nil){
        if (Prev(P) == Nil){
            DelFirst(L,&P);
        }
        else if (Next(P) == Nil){
            DelLast(L,&P);
        }
        else {
            address Q = Last(*L);
            address R;
            while(Q != P){
                R = Prev(Q);
                Info(Q) = Info(R);
                Q = Prev(Q);
            }
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
        Dealokasi(P);
    }
}

void PrintForward (List L){
    address P = First(L);
    if (IsEmpty(L)){
        printf("[]");
    }
    else {
        printf("[");
        while(P!=Nil){
            if(P!=Last(L)){
                printf("%d,",Info(P));
            }
            else {
                printf("%d", Info(P));
            }
            P = Next(P);
        }
        printf("]");
    }
}

void PrintBackward (List L){
    address P = Last(L);
    if (IsEmpty(L)){
        printf("[]");
    }
    else {
        printf("[");
        while(P!=Nil){
            if(P!=First(L)){
                printf("%d,",Info(P));
            }
            else {
                printf("%d", Info(P));
            }
            P = Prev(P);
        }
        printf("]");
    }
}

POINT GetLastPos(List L){
    return Pos(Last(L));
}


