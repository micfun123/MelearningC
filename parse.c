#include <stdio.h>
#include <string.h>

char parser(char myString[],int string_size){

    for (size_t i = 0; i < string_size; i++)
    {
        if (myString[i] == ' ')
        {
            myString[i] = '\0';
            printf("%s\n",myString[i]);
        }
    }
    
    
}

void main(){

    char myString[] = "Hello World!";
    parser(myString,sizeof(myString));

}