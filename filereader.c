#include <stdio.h>
#include <stdlib.h>

int main()
{   
    FILE *fptr;
    fptr = fopen("file.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char str[100]; //makes a arracy
    while (fgets(str, 100, fptr) != NULL) //copy file to array
    {
        printf("%s", str);//print array
    }

    fclose(fptr);
    return 0;
}

