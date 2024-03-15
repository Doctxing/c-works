// code here
//
// Created by doctxing on 23-10-28.
//
#include "stdio.h"
#include "ctype.h"
#define N 100
int get_num(int *n){
    int len=0;char temp;
    for (;(temp=getchar())!='\n'; len++ ) {
        if(isalnum(temp)){
            n[len]= (int)temp - 48;//0的ASCII为48
        } else len--;
    }
    return len+1;
}
//本程序是顺序读取，按照位置进行运算，顺序输出
int get_cul(int *a,int *b,int *c){
    int len_a= get_num(a),len_b= get_num(b);
    int len_c=(len_a>len_b?len_a:len_b),len_min=len_a<len_b?len_a:len_b;
    for (int i = 0; i < len_min; ++i) {
        c[len_c-i]+=(a[len_a-1-i]+b[len_b-1-i])%10;
        c[len_c-1-i]+=(a[len_a-1-i]+b[len_b-1-i])/10;
    }
    for (int i = len_min; i < len_c; ++i) {
        c[len_c-i]+=len_a>len_b?a[len_a-1-i]:b[len_b-1-i];
    }
    return len_c;
}
//顺序输出
void printout(int *c,int len_c){
    int i=0;
    for (;c[i]==0;i++);
    for (;i<len_c;i++) {
        printf("%d",c[i]);
    }
}

int main(void){
    int a[N]={0},b[N]={0},c[N]={0};
    int len_c;
    len_c= get_cul(a,b,c);
    printout(c,len_c);
    return 0;
}