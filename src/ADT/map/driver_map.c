#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main()
{
    Map M;
    printf("buat map empty, validasi IsEmptyMap, display map\n");
    CreateEmptyMap(&M);
    printf("IsEmpty = %d\n", IsEmptyMap(M));
    displayMap(M);

    printf("insertmap, value map, display map, isfull, ismember\n");
    InsertMap(&M, "lala", 11);
    InsertMap(&M, "zilla", 11);
    InsertMap(&M, "mufi", 11);
    ValueMap(M, "lala");
    displayMap(M);
    printf("IsFull= %d\n", IsFullMap(M));
    printf("IsMember= %d\n", IsMemberMap(M, "lala"));

    printf("IsMemberMapUnique\n");
    IsMemberMapUnique(M, "zilla");

    printf("delete map\n");
    DeleteMap(&M, "zilla");
    displayMap(M);
}
