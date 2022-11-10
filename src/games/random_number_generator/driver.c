#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_number_generator.h"

int main(){
  RNG();
    int score;
    int x = 20;
    if (score<10){
        RNG(x*2);
    }
    else if (score<20){
        RNG(x+24);
    }
    else if (score<30){
        RNG(x-11);
    }
    else if (score<40){
        RNG(x*3);
    }
    else {
        RNG(x+27);
    }  
    }