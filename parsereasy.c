#include <stdio.h>
#include <string.h>

char parser(char myString[]){

    char *token;
    token = strtok(myString," ");
    while (token != NULL)
    {
        printf("%s\n",token);
        token=strtok(NULL," ");
    }
      

}

void main(){

    char myString[] = "Hello World";
    parser(myString);

}