#include <stdio.h>
#include <string.h>
#include "ctype.h"
#include <time.h>
#define BOM_SIZE 3
#define MIN(a,b,c) ((a<b?a:b)<c?(a<b?a:b):c)
typedef struct{
    int a;
    char words[1700][20];
}VOC;
typedef struct{
    int num;
    int cont_num;
    char content[10][20];
}DATA;

FILE* OpNoBOM(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the first few bytes to check for BOM
    char bom[BOM_SIZE + 1];
    if (fread(bom, 1, BOM_SIZE, file) != BOM_SIZE) {
        if (feof(file)) { // Check if end of file is reached
            // No BOM detected, rewind the file pointer to the beginning
            rewind(file);
        } else {
            perror("Error reading file");
            fclose(file);
            return NULL;
        }
    } else if (strncmp(bom, "\xEF\xBB\xBF", BOM_SIZE) == 0) {
        printf("BOM detected, skipping...\n");
    } else {
        // No BOM detected, rewind the file pointer to the beginning
        rewind(file);
    }
    return file;
}

void read_classify(FILE* file,VOC vcbly[]){
    char temp[20];
    for (int i = 0; i < 20; ++i) {
        vcbly[i].a=0;
    }
    for (;fscanf(file,"%s",temp)!=EOF;){
        //scan once,and give to neighbors
        int len= strlen(temp);
        strcpy(vcbly[len - 1].words[vcbly[len - 1].a], temp);
        vcbly[len - 1].a++;
        if(len<20){
            strcpy(vcbly[len].words[vcbly[len].a], temp);
            vcbly[len].a++;
        }
        if(len-2>=0){
            strcpy(vcbly[len - 2].words[vcbly[len - 2].a], temp);
            vcbly[len - 2].a++;
        }
    }
    //test //for (int i = 0; i < 16; ++i) printf("out%d\n",vcbly[i].a);
}
//Levenshtein Distance
int leven(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + MIN(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}
void cvs2DA(char in[], DATA* out){
    for (int i = 0;in[i]!='\0'; ++i) {
        if(isalnum(in[i])==0&&in[i]!='-'&&in[i]!='\'') in[i]=' ';
    }
    out->cont_num=0;
    char *ptr=in;
    while (*ptr == ' ') ptr++;
    sscanf(ptr, "%d", &(out->num));
    while (*ptr != '\0' && *ptr != ' ') ptr++;
    while (*ptr == ' ')ptr++;
    while (*ptr != '\0') {
        if(sscanf(ptr, "%s", out->content[out->cont_num])==1) out->cont_num++ ;
        while (*ptr != '\0' && *ptr != ' ') ptr++;
        while (*ptr == ' ')ptr++;
    }
}
void read_process(FILE *file,FILE *fo,VOC check[]){
    for (int i=0;!feof(file);i++) {
        DATA words;
        char temp[72];
        fgets(temp,sizeof(temp),file);
        cvs2DA(temp,&words);

        for (int j = 0; j < words.cont_num; ++j) {
            if(strlen(words.content[j])>2){
                int ifsame=0;
                for (int k = 0; k < check[strlen(words.content[j])-1].a && ifsame==0; ++k) {
                    if(strcmp(words.content[j],check[strlen(words.content[j])-1].words[k])==0) ifsame=1;
                }
                if(ifsame==0){
                    int nums[check[strlen(words.content[j])-1].a];
                    int position=0,k=-1;
                    do {k++;
                        nums[k]=leven(words.content[j],check[strlen(words.content[j])-1].words[k]);
                        if (nums[position]>nums[k]) position=k;
                    } while (k < check[strlen(words.content[j])-1].a && nums[k]!=0);
                    if (nums[position]==1){
                        strcpy(words.content[j],check[strlen(words.content[j])-1].words[position]);
                    }
                }
            }
        }
        if(temp[0]!='\0'){
            fprintf(fo, "%04d %s ", words.num, words.content[0]);
            for (int j = 1; j < words.cont_num - 1; ++j) {
                fprintf(fo, "%s/", words.content[j]);
            }
            fprintf(fo, "%s\n", words.content[words.cont_num - 1]);
        }
        temp[0]='\0';
    }
}



void main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    FILE* fpv=OpNoBOM("vocabulary.txt");
    FILE* fpw= OpNoBOM("words.txt");
    FILE *pout= fopen("words_correct.txt","w+");
    VOC vocabulary[20];
    read_classify(fpv,vocabulary);
    read_process(fpw,pout,vocabulary);
    end = clock();
    printf("Done!Program execution time: %.4f seconds\n",((double) (end - start)) / CLOCKS_PER_SEC);
    fclose(fpv);
    fclose(fpw);
    fclose(pout);
}