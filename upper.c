#include <stdio.h>

void all_upper(char* str)
{
    // if str is empty, return
    if (str == NULL) {
        printf("NULL\n");
        return;
    }
    if (str[0] == '\0') {
        printf("Empty String\n");
        return;
    }

    char* p = str;
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32; 
        }
        p++;
    }

}

int main()
{
    char str1[] = "Gargantua is drinking tea.";
    all_upper(str1);
    printf("%s\n", str1); // Should print "GARGANTUA IS DRINKING TEA."

    char str2[] = "Tea is drunk by Tea.";
    all_upper(str2);
    printf("%s\n", str2); // Should print "TEA IS DRUNK BY TEA."

    char str3[] = ""; 
    all_upper(str3);
    printf("%s\n", str3); 

    return 0;
}
