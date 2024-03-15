//
// Created by dr-xi on 2023/10/16.
//
#include "stdio.h"
int ifgood(int a){//撤回输出数字的因数个数
    int counter=1;
    if(a==1)return 1;
    else{
        for (int i = 2; i < a / 2 + 1; ++i) {
            if(a%i==0)counter++;
        }
        return counter+1;
    }
}
int main(void){
    int min,max,counter=0;
    scanf("%d%*c%d",&min,&max);
    for (int i = min; i <= max-2; ++i) {
        if (ifgood(i)==2&& ifgood(i+2)==2){//他是质数并且他加2也是质数
            printf("(%d,%d)",i,i+2);
            counter++;
        }
    }
    printf("\n%d",counter);
}