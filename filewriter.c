#include <stdio.h>
#include <stdlib.h>

int main()
{   
    FILE *fptr;
    fptr = fopen("file.txt", "w");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    int write = 1;
    while (write)
    {
        char str[100];
        printf("Enter a sentence: ");
        gets(str);
        fprintf(fptr,"%s\n", str);
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &write);
        
    }
    






}