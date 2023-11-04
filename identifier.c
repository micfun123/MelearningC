#include <stdio.h>
#include <stdbool.h>

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
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
            if (!(isLetter(identifier[i]) || isDigit(identifier[i])))
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
    char testidentifier2[] = "int2";
    char testidentifier3[] = "INT";
    char testidentifier4[] = "";
    char testidentifier5[] = "_int";
    char testidentifier6[] = "int_";

    printf("%s\n", check_identifier(testidentifier) ? "true" : "false");
    printf("%s\n", check_identifier(testidentifier2) ? "true" : "false");
    printf("%s\n", check_identifier(testidentifier3) ? "true" : "false");
    printf("%s\n", check_identifier(testidentifier4) ? "true" : "false");
    printf("%s\n", check_identifier(testidentifier5) ? "true" : "false");
    printf("%s\n", check_identifier(testidentifier6) ? "true" : "false");



    return 0;
}
