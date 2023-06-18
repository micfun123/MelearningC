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

    int type = 0;
    printf("Press 1 for ordered list and 0 for un un ordered list: ");
    scanf("%d", &type);
    if (type != 1 && type != 0)
    {
        printf("This is not a valid input for a choice.");
        exit(1);
    }

    fprintf(fptr2,"<html>\n<body>\n");


    if (type == 1)
    {
        fprintf(fptr2,"<ol>\n");
    }
    else
    {
        fprintf(fptr2,"<ul>\n");
    }

    while (fgets(str, 100, fptr) != NULL) //copy file to array
    {
        fprintf(fptr2,"<li>%s</li>\n", str);//print array
    }
    

    if (type == 1)
    {
       fprintf(fptr2,"</ol>");
    }
    else
    {
        fprintf(fptr2,"</ul>");
    }


    fprintf(fptr2,"\n</body>\n</html>\n");

    fclose(fptr);
    fclose(fptr2);
    
    
    return 0;
}