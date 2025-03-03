// code here
// Created by dr-xi on 2023/10/19.
//
#include "stdio.h"

int main(void){
    int num;
    scanf("%d",&num);
    int fish_data[num],more[num];
    for (int i = 0; i < num; ++i) {
        scanf("%d%*c",&fish_data[i]);//读取数字
    }
    for (int i = 0; i < num; ++i) {
        more[i]=0;
        for (int j = 0; j < i; ++j) {
            if(fish_data[j]<fish_data[i])//站在一个位置上看前面有多少个小的，则＋＋
            more[i]++;
        }
    }
    for (int i = 0; i < num-1; ++i) {
        printf("%d ",more[i]);//带空格输出
    }
    printf("%d",more[num-1]);//不带空格输出
}