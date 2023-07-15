#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void main(){
    if (CreateDirectory("images", NULL) || ERROR_ALREADY_EXISTS == GetLastError())
    {
        printf("Directory created\n");
    }
    if (CreateDirectory("music", NULL) || ERROR_ALREADY_EXISTS == GetLastError())
    {
        printf("Directory created\n");
    }
    if (CreateDirectory("documents", NULL) || ERROR_ALREADY_EXISTS == GetLastError())
    {
        printf("Directory created\n");
    }
    if (CreateDirectory("videos", NULL) || ERROR_ALREADY_EXISTS == GetLastError())
    {
        printf("Directory created\n");
    }
    if (CreateDirectory("other", NULL) || ERROR_ALREADY_EXISTS == GetLastError())
    {
        printf("Directory created\n");
    }

    //go through all files in current directory
    //if file is image, move to images

    int sorted = 0;
    

}