//
// Created by dr-xi on 2023/10/16.
//
#include "stdio.h"
int otu(int n){
    if(n==1)return 1;
    else if(n==2)return 2;
    else{
        return 2*otu(n-1)+otu(n-2);//用了递归算法计算an
    }
}

int main(void){
    int a1=1,a2=2,n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", otu(a[i]));
    }
}