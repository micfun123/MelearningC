#include <stdio.h>

int len(char* str)
{
    int count = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            if (count != 0) {
                printf("%d ", count); 
                count = 0;
            }
        }
        else {
            count++;
        }
        str++;
    }
    printf("%d\n", count); 
}

int main()
{
    char str1[] = "gargantua        is drinking tea.               ";
    len(str1);
    char str2[] = "Tea is drunk by tea."; 
    len(str2);
    char str3[] = "";
    len(str3);
    return 0;
}