#include <stdio.h>
#include <point.h>

int main() {
    // Kamus
    POINT P1;
    POINT P2;
    float d;

    // Algoritma
    printf("Masukkan point 1: ");
    BacaPOINT(&P1);
    TulisPOINT(P1);
    printf("\nJarak0: %f\n", Jarak0(P1));
    printf("Masukkan point 1: ");
    BacaPOINT(&P2);
    TulisPOINT(P2);
    printf("\nJarak0: %f\n", Jarak0(P2));
    printf("Panjang: %f\n", Panjang(P1, P2));
    printf("Masukkan derajat rotasi: ");
    scanf("%f", &d);
    Putar(&P1, d);
    printf("Posisi setelah rotasi: ");
    TulisPOINT(P1);
}