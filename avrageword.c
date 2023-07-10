#include <stdio.h>

//find the average word length 
char words[100] = "This is a test string";

int main()
{
    int count = 0;
    int wordCount = 0;
    int total = 0;
    for (int i = 0; words[i] != '\0'; i++)
    {
        if (words[i] == ' ')
        {
            total += count;
            count = 0;
            wordCount++;
        }
        else
        {
            count++;
        }
    }
    total += count;
    wordCount++;
    printf("Average word length: %d\n", total / wordCount);
}