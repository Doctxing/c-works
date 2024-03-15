//
// Created by dr-xi on 2023/10/10.
//
#include "stdio.h"
#define LEN 1000
int if_gn(int n){//为检验是否为质数，1－>1,其他－>因数－2
    if (n==1)
        return 1;
    else{
        int counter=0;
        for (int i = 2; i < n/2 + 1; ++i) {
            if(n%i==0)
                counter++;
        }
        return counter;
    }
}
int main(void){
    int M;
    scanf("%d",&M);
    int num[M][LEN],temp[M];
    for (int i = 0; i < M; ++i) {
        int N;
        scanf("%d",&N);
        for (int j = 0; j < N; ++j) {
            scanf("%d%*c",&num[i][j]);
            temp[i]+=if_gn(num[i][j])?0:num[i][j];//如果是质数就加上
        }

    }
    for (int i = 0; i < M; ++i) {
        printf("%d\n",temp[i]);
    }
}