#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void main() {
    //enter your name 
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\e[1;1H\e[2J");
    printf("Hello, %s!\n", name);
    sleep(1);
    printf("\e[1;1H\e[2J");
    int progress = 1;
    while (progress < 100)    {
        printf("Hello, %s!\n", name);
        printf("Deep scan is running to determing your awesomeness \n");
        
        char bar[101];
        bar[0] = '[';
        for (size_t i = 1; i < progress; i++)
        {
            bar[i] = '#';
        }
        for (size_t i = progress; i < 100; i++)
        {
            bar[i] = ' ';
        }
        bar[100] = ']';
        bar[100] = '\0';
        progress = progress +5;
        printf("%s]\n", bar);        
        sleep(1);
        printf("\e[1;1H\e[2J");
    }
    printf("\e[1;1H\e[2J");
    printf("So, %s The results are in\n", name);
    Sleep(10);
    printf("you are\n");
    Sleep(10);
    printf("100 %% awesome\n");
    
}