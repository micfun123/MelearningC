#include <stdio.h>

void reverse(char *str){

    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    printf("%d\n", len);
    for (int i = len; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    
}

int main(){
    char str[] = "Hello";
    reverse(str);

    return 0;
}