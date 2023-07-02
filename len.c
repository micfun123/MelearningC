#include <stdio.h>

int len(char* str)
{
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main()
{
    char str1[] = "gargantua is drinking tea.";
    printf("%d\n", len(str1));

    char str2[] = "Tea is drunk by tea.";
    printf("%d\n", len(str2)); 

    char str3[] = ""; 
    printf("%d\n", len(str3));

    return 0;
}