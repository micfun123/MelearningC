#include <stdio.h>
#include <string.h>

long int wordcount = 0;

int wordcounter(const char* filename) {
    FILE *fptr;
    fptr = fopen( filename, "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 0;
    }
    char c;
    int count = 0;
    while ((c = fgetc(fptr)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            count++;
        }
    }
    count++;
    fclose(fptr);
    return count;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        wordcount = wordcounter(argv[i]);
        printf("Word count in %s: %ld\n", argv[i], wordcount);
    }
    return 0;
}

