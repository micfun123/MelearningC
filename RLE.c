#include <stdio.h>

void RLE(char* str)
{
    char* p = str;
    int count = 1;
    while (*p != '\0') {
        if (*p == *(p+1)) {
            count++;
        } else {
            printf("%d%c", count, *p);
            count = 1;
        }
        p++;
    }
    
}

void RLE_Decode(char* str)
{
    char* p = str;
    int count = 0;
    while (*p != '\0') {
        if (*p >= '0' && *p <= '9') {
            count = count * 10 + *p - '0';
        } else {
            for (int i = 0; i < count; i++) {
                printf("%c", *p);
            }
            count = 0;
        }
        p++;
    }
}


int main(void) {
    char str[] = "aaabbcd";
    RLE(str);
    printf("\n");
    char str2[] = "3a2b1c1d";
    RLE_Decode(str2);
    
    return 0;
}
