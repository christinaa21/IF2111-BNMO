/* *** Definisi ABSTRACT DATA TYPE POINT *** */
/* Sultan Alta ALvaro Valencia
18221110*/

#include <stdio.h>
#include "point.h"
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
    Absis(P)=X;
    Ordinat (P)=Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2]


   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float X,Y;
    scanf ("%f %f",&X, &Y);
    *P=MakePOINT(X,Y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return ((Absis(P1)!=Absis(P2)) || (Ordinat(P1)!=Ordinat(P2)));
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    return ((Absis(P)==0) && (Ordinat(P)==0));
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P)==0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    int kuadran;
    if (Absis(P)>0 && Ordinat(P)>0){
        kuadran=1;
    }
    else if (Absis(P)<0 && Ordinat(P)>0){
        kuadran=2;
    }
    else if (Absis(P)<0 && Ordinat(P)<0){
        kuadran=3;
    }
    else if (Absis(P)>0 && Ordinat(P)<0){
        kuadran=4;
    }
    return kuadran;
}