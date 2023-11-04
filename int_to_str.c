#include <stdio.h>

char out[5000];


//int_to_str converts an integer to a string
void int_to_str(int x)
{
    //wipe out the string
    for (int k = 0; k < 100; k++)
    {
        out[k] = '\0';
    }
    char str[100];
    int i = 0;
    while (x != 0)
    {
        str[i] = x % 10 + '0';
        x /= 10;
        i++;
    }
    //reverse the string
    int j = 0;
    char temp;
    while (j < i / 2)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
        j++;
    }
    str[i] = '\0';
    for (int k = 0; k < i; k++)
    {
        out[k] = str[k];
    }

}

int main()
{
    //test the function

}


