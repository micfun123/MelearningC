#include <stdio.h>

int height; 

int main(){

    do{
        printf("Please enter a height: ");
        scanf("%d", height);
    }while (height < 1);
    
    for (int line = 0; line < height; line++)
    {

        for (int space = height - 1; space > line; space = space - 1)   //prints spaces
        {
            printf(" ");
        }

        for (int hash = - 1; hash < line; hash++)   //prints hashes
        {

            printf("#");
        }

        printf("\n"); //new line
    }

    

}
