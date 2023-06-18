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
    fprintf(fptr2,"<html>\n<ul>\n");
    while (fgets(str, 100, fptr) != NULL) //copy file to array
    {
        fprintf(fptr2,"<li>%s</li>\n", str);//print array
    }
    fprintf(fptr2,"</ul>\n</html>\n");
    fclose(fptr);
    fclose(fptr2);
    return 0;
}