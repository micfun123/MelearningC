#include <stdio.h>

int x = 4452;
char out[5000];


//int_to_str converts an integer to a string
char int_to_str(int x)
{
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
    int_to_str(x);
    printf("%s\n", out);
    return 0;
}


