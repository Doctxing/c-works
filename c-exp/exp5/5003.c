// code here
//
// Created by dr-xi on 2023/10/20.
//
#include "stdio.h"
int pow2(int x,int y){
    int temp=x;
    if(y==0){
        return 1;
    }
    else{
        for (int i = 1; i < y; ++i) {
            x*=temp;
        }
        return x;
    }
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void replace(int a[],int len){
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            if(a[i]>a[j])
                swap(&a[i],&a[j]);
        }
    }
}
int main(void){
    int cmp[9]={1,2,3,4,5,6,7,8,9};
    for (int i = 1; i <=333 ; ++i) {//以第一个数字为基础检索，1000/3＝333，以此减小计算
        int temp[9]={0},temp2=9;
        for (int j = 0; j < 9; ++j) {
            temp[j]=((i*(j/3+1))/(pow2(10,(2-j%3))))%10;
        }
        replace(temp,9);
        for (int j = 0; j < 9; ++j) {
            if(temp[j]==cmp[j])temp2--;
        }
        if(temp2==0){//符合条件就打印
            printf("%03d,%03d,%03d\n",i,2*i,3*i);
        }
    }
}