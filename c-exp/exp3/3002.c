//
// Created by dr-xi on 2023/10/10.
//
#include "stdio.h"
#define len 1000

int main(void){
    int n,num[len]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%*c",&num[i]);
    }
    int p=num[0],q=num[0];
    for (int i = 0; i < n; ++i) {//遍历一遍找到最小与最大
        p=num[i]>p?num[i]:p;
        q=num[i]<q?num[i]:q;
    }
    printf("%d",p-q);//找到差值
    return 0;
}