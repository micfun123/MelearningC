#include <stdio.h>
#include <stdbool.h>

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool check_identifier(char *identifier)
{
    int i = 0;
    if (isLetter(identifier[i]))
    {
        i++;
        while (identifier[i] != '\0'){
            if (!isLetter(identifier[i]) || isDigit(identifier[i]))
            {
                return false;
            }
            i++;
            
        }
        return true;
    }
    return false;
}

int main()
{
    char testidentifier[] = "int";
    if (check_identifier(testidentifier))
    {
        printf("This is a valid identifier\n");
    }
    else
    {
        printf("This is not a valid identifier\n");
    }
    char testidentifier[] = "2int";
    if (check_identifier(testidentifier))
    {
        printf("This is a valid identifier\n");
    }
    else
    {
        printf("This is not a valid identifier\n");
    }

    return 0;
}
