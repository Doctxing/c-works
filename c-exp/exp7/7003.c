// code here
//
// Created by doctxing on 23-10-30.
//
#include "stdio.h"
#define N 80
//检验是否为子串
int main(void){
    int a_=0,b_=0;
    char a[N],b[N],temp;
    for (;(temp=getchar())!='\n'; ++a_) {
        a[a_]=temp;
    }
    for (;(temp=getchar())!='\n'; ++b_) {
        b[b_]=temp;
    }
    for (int i = 0; i < b_; ++i) {
        int num=0;
        for (int j = 0; j < a_; ++j) {
            if(b[i]==a[j])num=1;
        }
        if(num==0){
            printf("No");
            goto end;
        }
    }
    printf("Yes");
    end:return 0;
}
