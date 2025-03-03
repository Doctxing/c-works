//
// Created by dr-xi on 2023/10/16.
//
#include "stdio.h"

int main(void){
    int a[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    int days=365,counter=0,y;
    scanf("%d",&y);
    for (int i = 1901; i <= y ; ++i) {
        for (int j = 0; j < 12; ++j) {
            days+=a[(i%100!=0&&i%4==0)||(i%400==0)][j];//检测是否闰年
            if(days%7==6)counter++;
        }
    }
    printf("%d",counter);
}