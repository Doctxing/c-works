//
// Created by dr-xi on 2023/10/10.
//
#include "stdio.h"

int main(void){
    int R,Y;
    float M;
    scanf("%d %f %d",&R,&M,&Y);
    for (int i = 0; i < Y; ++i) {
        M*=(1+R/100.0);
    }
    printf("%d",(int)M);
}