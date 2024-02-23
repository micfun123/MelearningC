#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *bitmap;
int size; 
int width;
int hight;



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
    width = *(int *)&bitmap[18];
    hight = *(int *)&bitmap[22];





}

int main(){

    openfile("bitmap.bmp");
    printf("Size of the file in bytes: %d\n", size);
    printf("Width in pixels: %d\n", width);
    printf("High in pixels: %d\n", hight);

    free(bitmap);
    return 0;   

}