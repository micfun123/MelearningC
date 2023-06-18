#include <stdio.h>
#include <math.h>
#include <string.h>

int fizzbuzz(int n){

    //make a blank string
    char str[100] = "";
    if (n % 3 == 0)
    {
        strcat(str, "Fizz");
    }
    if (n % 5 == 0)
    {
        strcat(str, "Buzz");
    }
    if (strlen(str) == 0)
    {
        sprintf(str, "%d", n);
    }
    printf("%s\n", str);
    return 0;
}

int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        fizzbuzz(i);
    }

}