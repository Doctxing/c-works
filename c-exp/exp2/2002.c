#include "stdio.h"
int main(void){
    int put_num,counter=0;
    scanf("%d",&put_num);
    //如果能被3整除则输出其
    if(put_num%3==0){
        printf("3");
        counter++;
    }
    if(put_num%5==0){
        //如果是第一个数字那么就不打印空格
        if(counter)
            printf(" ");
        printf("5");
        counter++;
    }
    if(put_num%7==0){
        //与5同理
        if(counter)
            printf(" ");
        printf("7");
        counter++;
    }
    if(counter==0)
        printf("n");
}