#include <stdio.h>
#include "point.h"

int main(){
    POINT P = MakePOINT(2,5);
    printf("%d %d\n", Absis(P), Ordinat(P));
    POINT Q;
    BacaPOINT(&Q);
    printf("%d %d\n", Absis(Q), Ordinat(Q));

    printf("Equal = %d\n", EQ(P,Q));
    printf("NotEqual = %d\n", NEQ(P,Q));
    printf("IsOrigin = %d\n", IsOrigin(Q));
    printf("IsOnSbX = %d\n", IsOnSbX(Q));
    printf("IsOnSbY = %d\n", IsOnSbY(Q));
    printf("Kuadran P = %d; Kuadran Q = %d\n", Kuadran(P), Kuadran(Q));
}