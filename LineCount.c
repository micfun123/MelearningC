#include <stdio.h>
#include <stdlib.h>

int main()
{   
    FILE *fptr;
    fptr = fopen("file.txt", "r");
    if (fptr == NULL)
    {
        printf("No file found!");
        exit(1);
    }

    int LineCount = 0;
    char str[100]; //makes a arracy
    while (fgets(str, 100, fptr) != NULL) //copy file to array
    {
        LineCount++;
    }
    fclose(fptr);
    printf("%d",LineCount);
    return 0;
}