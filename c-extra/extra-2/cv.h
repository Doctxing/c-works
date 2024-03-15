#ifndef CV_H
#define CV_H
# include "stdbool.h"
typedef struct
{
    unsigned int bfSize;  //文件大小
    unsigned short fReserved1;  //保留字
    unsigned short fReserved2;  //保留字
    unsigned int fOffBits;  //位图数据偏移字节数
} BitMapFileHeader;  /*文件头*/

typedef struct
{
    unsigned int biSize;   //结构体长度
    int biWidth;   //位图宽度
    int biHeight;   //位图高度
    unsigned short biPlanes;   //位图平面数
    unsigned short biBitCount;  //颜色位数
    unsigned int biCompression;   //压缩方式
    unsigned int biSizeImage;   //实际位图数据占用的字节数
    int biXPelsPerMeter;   //X方向分辨率
    int biYPelsPerMeter;   //Y方向分辨率
    unsigned int biClrUsed;   //使用的颜色数
    unsigned int biClrImportant;   //重要颜色数
} BitMapInfoHeader;  /*位图信息头*/

typedef struct
{
    unsigned char B;
    unsigned char G;
    unsigned char R;
} PixelBlock;

typedef struct
{
    int width;
    int height;
    int channels;
    PixelBlock* imageData;
}BMPImage;


BMPImage* LoadBMPImage(char* path);
BMPImage *Convolution2D(BMPImage *img,int a);
bool SaveBMPImage(char* path, BMPImage* bmpImg);

#endif

