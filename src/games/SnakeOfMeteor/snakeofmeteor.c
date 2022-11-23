#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "snakeofmeteor.h"

void printmap(List L, POINT M, POINT F){
    int i,j;
    POINT S;
    for(i = 0;i<11;i++){
        for(j=0;j<11;j++){
            if(i % 2 == 0){
                if (j % 2 == 0){
                    printf(" ");
                }
                else {
                    printf("---");
                }
            }
            else {
                if(j % 2 == 0){
                    printf("|");
                }
                else {
                    S.x = j/2;
                    S.y = i/2;
                    if(Search(L,S)!=Nil){
                        if(M.x == S.x && M.y == S.y){
                            printf(" m ");
                        }
                        else {
                            printf(" %c ", Search(L,S)->info);
                        }
                        
                    }
                    else {
                        if(F.x == S.x && F.y == S.y){
                            printf(" o ");
                        }
                        else if(M.x == S.x && M.y == S.y){
                            printf(" m ");
                        }
                        else {
                            printf("   ");
                        }
                    }
                    
                    
                }
            }
        }
        printf("\n");
    }
}

POINT Food(List L){
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while (Search(L,P) != Nil){
        P.x = rand() % 5;
        P.y = rand() % 5;
    }
    return P;
}

POINT Meteor(POINT Food) {
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while(P.x == Food.x && P.y == Food.y){
        P.x = rand() % 5;
        P.y = rand() % 5;
    }
    return P;
}

void UserMove(List L, char input, boolean *GameOver){
    address P = First(L);
    *GameOver = false;
    POINT Temp;
    if (input == 'w'){
        Temp.x = Pos(P).x % 5;
        Temp.y = (Pos(P).y + 4) % 5;
    }
    else if(input == 'a'){
        Temp.x = (Pos(P).x + 4) % 5;
        Temp.y = Pos(P).y % 5;
    }
    else if(input == 's'){
        Temp.x = Pos(P).x % 5;
        Temp.y = (Pos(P).y + 1) % 5;
    }
    else if(input == 'd'){
        Temp.x = (Pos(P).x + 1) % 5;
        Temp.y = Pos(P).y % 5;
    }
    if(Search(L,Temp)!=Nil){
        *GameOver = true;
    }
    else {
        address Q;
        P = Last(L);
        while (P!=First(L)){
            Q = Prev(P);
            Pos(P).x = Pos(Q).x;
            Pos(P).y = Pos(Q).y;
            P = Prev(P);
        }
        Pos(P).x = Temp.x;
        Pos(P).y = Temp.y;
    }
}

void FirstRandSnake (List *L){
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    InsVLast(L,'H',P);
    if(P.x>=2){
        P.x-=1;
        InsVLast(L,'1',P);
        P.x-=1;
        InsVLast(L,'2',P);
    }
    else {
        if (P.x == 1){
            P.x-=1;
            InsVLast(L,'1',P);
            if (P.y == 0){
                P.y+=1;
                InsVLast(L,'2',P);
            }
            else {
                P.y-=1;
                InsVLast(L,'2',P);
            }
        }
        else if (P.x == 0){
            if(P.y >= 2){
                P.y -= 1;
                InsVLast(L,'1',P);
                P.y -= 1;
                InsVLast(L,'2',P);
            }
            else {
                if (P.y == 1){
                    P.y += 1;
                    InsVLast(L,'1',P);
                    P.y += 1;
                    InsVLast(L,'2',P);
                }
                else {
                    P.y += 1;
                    InsVLast(L,'1',P);
                    P.y += 1;
                    InsVLast(L,'2',P);
                }
            }
        }
    }
}

void SnakeOfMeteor(){
    List L;
    CreateEmpty(&L);
    FirstRandSnake(&L);
    POINT temp;
    POINT F = Food(L);
    POINT M = MakePOINT(5,5);
    printmap(L,M,F);
    int idk = 3;
    int turn = 1;
    char A[] = "a";
    char W[] = "w";
    char S[] = "s";
    char D[]  = "d";
    boolean GameOver = false;
    while(!GameOver){
        printf("TURN %d\n", turn);
        printf("Silahkan masukkan command anda: ");
        STARTINPUTKATA();
        printf("\n");
        while (!IsEqual(currentWord,A) && !IsEqual(currentWord,W) && !IsEqual(currentWord,S) && !IsEqual(currentWord,D)){
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
            printf("Silahkan masukkan command anda: ");
            STARTINPUTKATA();
            printf("\n");
        }
        
        temp = GetLastPos(L);
        UserMove(L,currentWord.TabWord[0], &GameOver);
        if(Pos(First(L)).x == F.x && Pos(First(L)).y == F.y){
            InsVLast(&L, idk +'0', temp);
            idk++;
            F = Food(L);
        }
        M = Meteor(F);
        printmap(L,M,F);
        if (Search(L,M) != Nil){
            if (Pos(First(L)).x == M.x && Pos(First(L)).y == M.y){
                GameOver = true;
            }
            DelP(&L,M);
            idk--;
        } 
        turn++;
    }
    printf("===== GAME OVER =====\n");
}

int main(){
   SnakeOfMeteor();
}
