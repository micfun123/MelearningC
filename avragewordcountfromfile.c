#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("file.txt", "r");

    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    printf("Size of file: %d\n", size);

    //save file to array of chars using malloc
    char *file = (char *)malloc(size * sizeof(char));
    fseek(fptr, 0, SEEK_SET);
    fread(file, sizeof(char), size, fptr);
    fclose(fptr);

    for (int i = 0; i < size; i++)
    {
        printf("%c", file[i]);
    }
    printf("\n");
    
    int count = 0;
    int wordCount = 0;
    int total = 0;
    for (int i = 0; file[i] != '\0'; i++)
    {
        if (file[i] == ' ')
        {
            total += count;
            count = 0;
            wordCount++;
        }
        else
        {
            count++;
        }
    }

    printf("Average word length: %d\n", total / wordCount);
}