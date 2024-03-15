#include "stdio.h"
#define D 20
#define PI 3.1415926
int main(void){
    int h,r,n=-1;
    float temp;
    scanf("%d %d",&h,&r);
    if(h>0&&r>0){
        temp=(h*PI*r*r)/1000.0;
        n=(int)(20/temp)+1;
    }
    printf("%d",n);
}