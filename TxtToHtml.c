#include <stdio.h>
#include <stdlib.h>

int main()
{   
    //input file TXT
    FILE *fptr;
    //output file HTML
    FILE *fptr2;

    fptr = fopen("file.txt", "r");
    fptr2 = fopen("file.html", "w");


    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char str[100]; //makes a arracy
    while (fgets(str, 100, fptr) != NULL) //copy file to array
    {
        fprintf(fptr2,"%s", str);
    }
    fclose(fptr);
    fclose(fptr2);
    return 0;
}