#include <stdio.h>

void reverse(char *str){

    int len = 0;
    char reverse_str[100] = {'\0'};
    while (str[len] != '\0')
    {
        len++;
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
    {
        reverse_str[i] = str[len - i - 1];
    }
    printf("%s\n", reverse_str);

    
}

int main(){
    char str[] = "Hello";
    reverse(str);

    return 0;
}