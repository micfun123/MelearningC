#include <stdio.h>
#include <stdlib.h>

int main()
{   
    FILE *fptr;
    FILE *fpts2;
    fptr = fopen("file.txt", "r");
    fpts2 = fopen("file2.txt", "w");
    if (fptr == NULL)
    {
        printf("No file found!");
        exit(1);
    }

    char str[100]; //makes a arracy
    while (fgets(str, 100, fptr) != NULL)
    {
        if (str[0] == '\n')
        {
            continue;
        }
        else
        {
            fprintf(fpts2,"%s",str);
        }
    }
    fclose(fptr);
    fclose(fpts2);
    return 0;
    

}