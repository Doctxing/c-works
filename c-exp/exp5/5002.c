// code here
//
// Created by dr-xi on 2023/10/20.
//
#include "stdio.h"
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
int delete(int a[],int len){//去掉重复的数字并且计算去掉的数量
    int temp=0;
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            if(a[i]==a[j]&&a[i]!=0)
                ++temp,a[j]=0;
        }
    }
    return temp;
}
int main (void){
    int num;
    scanf("%d",&num);
    int data[num];
    for (int i = 0; i < num; ++i) {
        scanf("%d%*c",&data[i]);
    }
    int temp=delete(data,num);//先删除
    printf("%d\n",num-temp);//后打印
    replace(data,num);//后排序
    for (int i = 0; i < num; ++i) {
        if(data[i]!=0)
            printf("%d ",data[i]);
    }
}