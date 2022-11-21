#include <stdio.h>
#include "listdp.h"

boolean IsEmpty (List L){
    return (First(L) == Nil && Last(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}
address Alokasi (infotype X){
    address P = (address) malloc (sizeof(ElmtList));
    if (P!=Nil){
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
    free(P);
}

address Search (List L, infotype X){
    address P = First(L);
    boolean ada = false; 
    while (P!=Nil && !ada){
        if(Info(P) == X){
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

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P!=Nil){
        if(!IsEmpty(*L)){
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
        else {
            First(*L) = P;
            Last (*L) = P;
        }
    }
}

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
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

void DelVFirst (List *L, infotype *X){
    address P = First(*L);
    *X = Info(P);
    if (Next(P) == Nil){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        First(*L) = Next(P);
        Prev(Next(P)) = Nil;
    }
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X){
    address P = Last(*L);
    *X = Info(P);
    if(Prev(P) == Nil){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        Last(*L) = Prev(P);
        Next(Prev(P)) = Nil;
    }
    Dealokasi(P);
}

void InsertFirst (List *L, address P){
    if(IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
    if(IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;   
    }
}

void InsertAfter (List *L, address P, address Prec){
    if (Next(Prec) == Nil){
        Last(*L) = P;
    }
    else {
        Prev(Next(Prec)) = P;
    }
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
}

void InsertBefore (List *L, address P, address Succ){
    if (Prev(Succ) == Nil){
        First(*L) = P;
    }
    else {
        Next(Prev(Succ)) = P;
    }
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
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

void DelP (List *L, infotype X){
    address P = First(*L);
    boolean ada = false;
    while (P!=Nil && !ada){
        if(Info(P) == X){
            ada = true;
        }
        else {
            P = Next(P);
        }
    }
    if (ada){
        if (Prev(P) == Nil){
            DelFirst(L,&P);
        }
        else if (Next(P) == Nil){
            DelLast(L,&P);
        }
        else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
        Dealokasi(P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    if(Next(*Pdel) == Nil){
        Last(*L) = Prec;
    }
    else {
        Prev(Next(*Pdel)) = Prec;
    }
}

void DelBefore (List *L, address *Pdel, address Succ){
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    if (Prev(*Pdel) == Nil){
        First(*L) = Succ;
    }
    else {
        Next(Prev(*Pdel)) = Succ;
    }
}

void PrintForward (List L){
    address P = First(L);
    if (IsEmpty(L) == Nil){
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
    if (IsEmpty(L) == Nil){
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



