#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

char *bitmap;
int32_t size;
int32_t width;
int32_t hight;
int32_t bitdepth;
int32_t pixel_offset;
int32_t totalpixels;




void openfile(char *filename){
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Error: File not found\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    size = length;
    bitmap = (char *)malloc(length);
    if (bitmap == NULL){
        printf("Error: Memory not allocated\n");
        exit(1);
    }
    fseek(file, 0, SEEK_SET);
    fread(bitmap, 1, length, file);
    fclose(file);

    //find the width and hight of the image
    width = *(int32_t *)&bitmap[18];
    hight = *(int32_t *)&bitmap[22];
    bitdepth = *(int32_t *)&bitmap[28];
    pixel_offset = *(int32_t *)&bitmap[10];
    //find the brightness of the image
    totalpixels = width * hight;
    printf("Total pixels: %d\n", totalpixels);
    long long int R = 0;
    long long int G = 0;
    long long int B = 0;

    for (int i = 0; i < totalpixels; i++){
        int offset = pixel_offset + (i * 3);
        int b = (unsigned char)bitmap[offset];
        int g = (unsigned char)bitmap[offset + 1];
        int r = (unsigned char)bitmap[offset + 2];
        R += r;
        G += g;
        B += b;

    }

    float brightness = (R + G + B) / (totalpixels * 255 * 3.0);
    printf("Brightness: %f\n", brightness);
}

int main(){

    openfile("dib24.bmp");
    printf("Size of the image: %d\n", size);
    printf("Width of the image: %d\n", width);
    printf("Hight of the image: %d\n", hight);
    printf("Bit depth of the image: %d\n", bitdepth);


    free(bitmap);
    return 0;   

}