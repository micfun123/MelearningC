#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *bitmap;
int size; 



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

}

int main(){

    openfile("bitmap.bmp");
    printf("Size of the file in bytes: %d\n", size);
    free(bitmap);
    return 0;   

}