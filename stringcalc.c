#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

size_t Pos;
const char *string;

bool End_of_String()
{
    return !(Pos < strlen(string));
}

void init_parse(const char in_string[])
{
    Pos = 0;
    string = in_string;
}

char get_char()
{
    // check if there are chars left to read else return 0. Makes it safe
    if (End_of_String())
        return 0;
    // gets the current byte (char) then moves the Pos falwards by one
    return string[Pos++];
}

char peek_char()
{
    // check if there are chars left to read else return 0. Makes it safe
    if (End_of_String())
        return 0;
    // looks at the current byte (char) with out moving falwards
    return string[Pos];
}

void Skip_WhiteSpace()
{
    while (peek_char() == ' ')
    {
        Pos++;
    }
}

bool allowed_char(char c)
{
    // 0-9 + - * / ( )
    return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

char get_digit()
{
    Skip_WhiteSpace();
    // find the next allowed digit
    char c = get_char();
    while (!allowed_char(c))
    {
        Skip_WhiteSpace();
        c = get_char();
    }
    return c;
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

double get_num()
{
    // get a int from the string up to the next non digit char
    int result = 0;

    Skip_WhiteSpace();
    while (is_digit(peek_char()))
    {
        // No skip whitespace here!
        int digit = get_char() - '0';
        result = result * 10 + digit;
        Skip_WhiteSpace();
    }
    return result;
}

double get_product()
{
    // a product is 1 or more numbers multiplied togeather
    double result = 1;
    result *= get_num();
    Skip_WhiteSpace();
    if (peek_char() == '*')
    {
        get_char();
        Skip_WhiteSpace();
        result *= get_num();
    }
    return result;
}

int main()
{
    //char myString[] = "2 * 2";
    //printf("%d\n", calc(myString));
    //char myString2[] = "23+22";
    //printf("%d\n", calc(myString2));

    init_parse("26 * 2");    
    printf("%f",get_product());

    return 0;
}