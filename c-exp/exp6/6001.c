// code here
// coded by doctxing
#include "stdio.h"
// no need to

int main(void){
    int num=0;
    printf("Input the total number of the students(n<40):\n");
    scanf("%d",&num);
    printf("Input student’s ID and score as: MT  EN  PH:\n");
    int stu[num][3],suml[num],sumr[3]={0};
    char stuinfo[num][9];
    for(int i=0;i<num;i++){
        scanf("%s",&stuinfo[i]);
        for(int j=0;j<3;j++){
            scanf("%d%*c",&stu[i][j]);
        }
    }
    printf("Counting Result:\n");
    printf("Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for(int i=0;i<num;i++){
        printf("   ");
        for(int cou=0;cou<9;cou++){
            printf("%c",*(*(stuinfo+i)+cou));
        }
        printf("\t");
        for(int j=0;j<3;j++){
            printf("%4d\t",stu[i][j]);
        }
        suml[i]=0;
        for(int j=0;j<3;j++){
            suml[i]+=stu[i][j];
            sumr[j]+=stu[i][j];
        }
        printf("%4d\t%5.1f\n",suml[i],suml[i]/3.0);
    }
    printf("SumofCourse \t");
    for(int j=0;j<3;j++){
        printf("%4d\t",sumr[j]);
    }
    printf("\nAverofCourse\t");
    for(int j=0;j<3;j++){
        printf("%4.1f\t",sumr[j]/(float)num);
    }

    return 0;
}