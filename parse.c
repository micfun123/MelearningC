#include <stdio.h>
#include <string.h>

char parser(const char myString[]){

    for (size_t i = 0; i < strlen(myString); i++)
    {
        if(myString[i] == ' '){
            if(myString[i-1] == ' '){
                continue;
            }
            else{
                printf("\n",myString[i]);
            }
        }
        else {
            printf("%c",myString[i]);
        }
    }
    
}

void main(){

    char myString[] = "          Hello       World! Hey    farther aka spider            it works. Am i a good sun?";
    parser(myString);

}