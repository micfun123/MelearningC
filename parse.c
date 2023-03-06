#include <stdio.h>
#include <string.h>

char parser(char myString[],int string_size){

    char *token;
    for (size_t i = 0; i < string_size; i++)
    {
        printf("%c\n",myString[i]);
    }
    
    
}

void main(){

    char myString[] = "Hello World!";
    parser(myString,sizeof(myString));

}