#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ERROR_NONE 0
#define ERROR_INVALID_CHAR 1
#define ERROR_UNEXPECTED_END_OF_STRING 2

size_t Pos;
const char *string;
int errorID = 0;
int errorPos = 0;



bool End_of_String()
{
    return !(Pos < strlen(string));
}

void init_parse(const char in_string[])
{
    Pos = 0;
    string = in_string;
    errorID = ERROR_NONE;
    
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

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

double get_num()
{
    // get a int from the string up to the next non digit char
    int result = 0;

    Skip_WhiteSpace();
    if (!is_digit(peek_char()))
    {
        errorID = ERROR_INVALID_CHAR;
        errorPos = Pos;
        return 0;
    }
    
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
    if(errorID != ERROR_NONE){
        return 0;
    }
    Skip_WhiteSpace();
    if(End_of_String()){
        return result;
    }
    if (peek_char() == '*')
    {
        get_char();
        Skip_WhiteSpace();
        if(End_of_String()){
            errorID = ERROR_UNEXPECTED_END_OF_STRING;
            errorPos = Pos;
            return 0;
        }
        result *= get_num();
        if(errorID != ERROR_NONE){
            return 0;
        }

    }
    return result;
}


char error_message(int errorID)
{
    switch (errorID)
    {
    case ERROR_NONE:
        printf("No Error");
        break;
    case ERROR_INVALID_CHAR:
        printf("Invalid Character");
        break;
    case ERROR_UNEXPECTED_END_OF_STRING:
        printf("Unexpected End of String");
        break;
    default:
        printf("Unknown Error");
    }
}

int main()
{
    //char myString[] = "2 * 2";
    //printf("%d\n", calc(myString));
    //char myString2[] = "23+22";
    //printf("%d\n", calc(myString2));

    init_parse("2*   *2");
    double result = get_product();
    if(errorID != ERROR_NONE){
        printf("Error: ");
        error_message(errorID);
        printf(" at position %d\n",errorPos +1);
        printf("%s\n",string);
        for(int i = 0; i < errorPos; i++){
            printf(" ");
        }
        printf("^\n");

    }
    else{
        printf("%f\n",result);
    }

    return 0;
}