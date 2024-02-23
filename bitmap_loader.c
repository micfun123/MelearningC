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
}

int main(){

    openfile("dib16.bmp");
    printf("Size of the image: %d\n", size);
    printf("Width of the image: %d\n", width);
    printf("Hight of the image: %d\n", hight);
    printf("Bit depth of the image: %d\n", bitdepth);


    free(bitmap);
    return 0;   

}