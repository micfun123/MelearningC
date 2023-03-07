#include <stdio.h>
#include <string.h>

char parser(char myString[],int string_size){

    for (size_t i = 0; i < string_size; i++)
    {
        if(myString[i] == ' '){
            myString[i] = '\n';
        }
        printf("%c",myString[i]);
    }
    
}

void main(){

    char myString[] = "Hello World! Hey farther aka spider it works. Am i a good son?";
    parser(myString,sizeof(myString));

}