#include <stdio.h>

int len(char* str)
{
    char ignore[] = {' ', '\t', ',', '.', '!', '?', '\n'};
    int count = 0;
    int ignored = 0;
    while (*str != '\0') {
        if (str == ignore) {
            str++;
        }
        for (int i = 0; i < 8; i++) {
            if (*str == ignore[i]) {
                str++;
                if (count != 0) {
                    printf("%d ", count);
                    count = 0;
                }
                ignored = 1;
            }
        }
        if (ignored == 1) {
            ignored = 0;
            str++;
        }
        else {
            count++;
            str++;
        }

    }
    printf("%d\n", count); 
    
}

int main()
{
    char str1[] = "gargantua        is drinking tea.           ";
    len(str1);
    char str2[] = "Tea is drunk by tea."; 
    len(str2);
    char str3[] = "";
    len(str3);
    return 0;
}