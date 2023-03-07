#include <stdio.h>
#include <string.h>

char parser(const char myString[],int string_size){

    for (size_t i = 0; i < string_size; i++)
    {
        if(myString[i] == ' '){
            printf("\n");
        }
        else {
            printf("%c",myString[i]);
        }
    }
    
}

void main(){

    char myString[] = "Hello World! Hey farther aka spider it works. Am i a good sun?";
    parser(myString,sizeof(myString));

}