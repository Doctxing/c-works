//code here
//
// Created by doctxing on 23-10-30.
//
#include "stdio.h"
//顺序排列从小到大
void replace_max(int *a,int *b){
    for (int i = 0; i < 4; ++i) {
        a[i]=b[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            if(a[j]>a[i]){
                int temp;
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}
//逆序排列从大到小
void replace_min(int *a,int *b){
    for (int i = 0; i < 4; ++i) {
        a[i]=b[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            if(a[j]<a[i]){
                int temp;
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}
//计算差值
void cal(int *max,int *min,int *out){
    int temp[4];
    for (int i = 0; i < 4; ++i) {
        temp[i]=max[i];
    }
    for (int i = 3; i >=0; --i) {
        if(temp[i]>=min[i])out[i]=temp[i]-min[i];
        else if(i>0){
            temp[i-1]--;out[i]=temp[i]+10-min[i];
        }
    }
}
//linux pow 有点问题于是自己写了一个
int mine_pow(int a,int b){
    if (b==0) return 1;
    else{
        int temp=a;
        for (int i = 1; i < b; ++i) {
            a*=temp;
        }
    }
    return a;
}
//类型转化从数组到整数
int num2in(int *a){
    int out=0;
    for (int i = 0; i < 4; ++i) {
        out+=(a[i]*mine_pow(10,3-i));
    }
    return out;
}

int main(void){
    int temp[4]={0},a[4],b[4];
    for (int i = 0; i < 4; ++i) {
        temp[i]=(int)getchar()-48;
    }
    int c= num2in(temp);
    for (int i = 0; c!=6174&&i<10; ++i) {
        replace_max(a,temp);
        replace_min(b,temp);
        cal(a,b,temp);
        c=num2in(temp);
        printf("[%d]:%d-%d=%d\n",i+1, num2in(a), num2in(b), c);
    }
}