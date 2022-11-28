#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main(){
    Set S;
    
    printf("create empty, isempty, displaySet\n");
    CreateEmptySet(&S); 
    printf("IsEmpty = %d\n", IsEmptySet(S));
    displaySet(S); 

    printf("insert, isfull, displaySet, ismember\n");
    InsertSet(&S, 2);
    displaySet(S);
    printf("IsMember = %d\n", IsMemberSet(S, 2));

    printf("Delete, displayset\n");
    DeleteSet(&S, 2); 
    displaySet(S);
}