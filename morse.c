#include <stdio.h>
#include <stdint.h>

int main(){

    char messageout[100];
    char messagein[100];
    char Alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                         'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char Morse[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                         ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                         "...","-","..-","...-",".--","-..-","-.--","--.."};
    printf("What is your message: ");
    scanf("%s",messageout);

    for (int i = 0; i < 100; i++)
    {
        if (messageout[i] == '\0')
        {
            break;
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (messageout[i] == Alphabet[j])
                {
                    printf("%s ",Morse[j]);
                }
            }
        }
    }



}