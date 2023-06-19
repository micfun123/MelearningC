#include <stdio.h>

void reverse(char *str){

    int len = 0;
    char reverse_str[100] = {'\0'};
    while (str[len] != '\0')
    {
        len++;
    }
    printf("%d\n", len);
    for (int i = len; i >= 0; i--)
    {
        reverse_str[i - 1] = str[len - i];
    }
    printf("%s\n", reverse_str);

    
}

int main(){
    char str[] = "Hello";
    reverse(str);

    return 0;
}