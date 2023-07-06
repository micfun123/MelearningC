#include <stdio.h>

//write a function to remove everything before the first dot in a string and everything after the next dot

char mystring[100] = "WWW.OCR.ORG.UK";
char mystring2[100] = "www.ocr.org.uk";

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


int hasher(char *site) {
    all_upper(site);
    int total = 0;
    int i = 0;
    while (site[i] != '.') {
        i++;
    }
    i++;
    while (site[i] != '.') {
        total += site[i];
        i++;
    }
    return total;
}



int main(void) {
    printf("%d\n", hasher(mystring));
    printf("%d\n", hasher(mystring2));
    return 0;

}
