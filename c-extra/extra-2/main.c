#include "stdio.h"
#include "stdlib.h"
#include "cv.h"

char name[3][16]={"gaussian.bmp","sculpture.bmp","outline.bmp"};

int main(int argc, char* argv[]){
    char path[64];
    printf("which bmp:");
    scanf("%s",path);
    BMPImage* img = LoadBMPImage(path);
    for (int i = 0; i < 3; ++i) {
        BMPImage* convdImg;
        convdImg = Convolution2D(img,i);
        if(SaveBMPImage(name[i], convdImg)){
            printf("%s image processed.\n",name[i]);
        }
        free(convdImg->imageData);
        free(convdImg);
    }

}
