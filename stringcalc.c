#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//defining the functions
void calc(const char *string);
double get_sum();
double get_product();
double get_num();
void Skip_WhiteSpace();
char get_char();
char peek_char();
bool End_of_String();
bool is_error();
void init_parse(const char in_string[]);



enum ErrorID
{
    ERROR_NONE,
    ERROR_INVALID_CHAR,
    ERROR_UNEXPECTED_END_OF_STRING
};

size_t Pos;
const char *string;
int errorID = 0;
int errorPos = 0;

bool End_of_String()
{
    return !(Pos < strlen(string));
}

bool is_error()
{
    return errorID != ERROR_NONE;
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
    while (peek_char() == ' ' || peek_char() == '\t' || peek_char() == '\n')
    {
        Pos++;
    }
}


bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

double get_num()
{
    // get a int from the string up to the next non digit char
    double result = 0;
    bool negative = false;
    if (peek_char() == '-')
    {
        negative = true;
        get_char();
    }
    if (peek_char() == '+')
    {
        get_char();
    }
    if (peek_char() == '(')
    {
        Skip_WhiteSpace();
        get_char();
        Skip_WhiteSpace();
        result = get_sum();
        if (is_error())
        {
            return 0;
        }
        if (peek_char() != ')')
        {
            errorID = ERROR_INVALID_CHAR;
            errorPos = Pos;
            return 0;
        }
        get_char();
        Skip_WhiteSpace();
        return result;
    }
    Skip_WhiteSpace();
    if (!is_digit(peek_char()))
    {
        errorID = ERROR_INVALID_CHAR;
        errorPos = Pos;
        return 0;
    }
    // set up negative number

    // get the number
    while (!End_of_String() && is_digit(peek_char()))
    {
        result *= 10;
        result += get_char() - '0';
        //check for decimal
        if (peek_char() == '.')
        {
            get_char();
            double decimal = 0;
            double decimal_place = 0.1;
            while (!End_of_String() && is_digit(peek_char()))
            {
                decimal += (get_char() - '0') * decimal_place;
                decimal_place *= 0.1;
            }
            result += decimal;
        }
    }
    if (negative)
    {
        result *= -1;
    }
    return result;
}

double get_product()
{
    // a product is 1 or more numbers multiplied togeather
    double result = 1;
    result *= get_num();
    if (is_error())
    {
        return 0;
    }
    Skip_WhiteSpace();
    while (!End_of_String() && (peek_char() == '*' || peek_char() == '/'))
    {
        if (peek_char() == '*')
        {
            Skip_WhiteSpace();
            if (End_of_String())
            {
                errorID = ERROR_UNEXPECTED_END_OF_STRING;
                errorPos = Pos;
                return 0;
            }
            get_char();
            result *= get_num();
            if (is_error())
            {
                return 0;
            }
            Skip_WhiteSpace();
        }
        else if (peek_char() == '/')
        {
            Skip_WhiteSpace();
            if (End_of_String())
            {
                errorID = ERROR_UNEXPECTED_END_OF_STRING;
                errorPos = Pos;
                return 0;
            }
            get_char();
            result /= get_num();
            if (is_error())
            {
                return 0;
            }
            Skip_WhiteSpace();
        }
    }
    return result;
}
double get_sum()
{
    double result = 0;
    result += get_product();
    if (is_error())
    {
        return 0;
    }
    Skip_WhiteSpace();
    while (!End_of_String() && (peek_char() == '+' || peek_char() == '-'))
    {
        if (peek_char() == '+')
        {
            Skip_WhiteSpace();
            if (End_of_String())
            {
                errorID = ERROR_UNEXPECTED_END_OF_STRING;
                errorPos = Pos;
                return 0;
            }
            get_char();
            result += get_product();
            if (is_error())
            {
                return 0;
            }
            Skip_WhiteSpace();
        }
        else if (peek_char() == '-')
        {
            Skip_WhiteSpace();
            if (End_of_String())
            {
                errorID = ERROR_UNEXPECTED_END_OF_STRING;
                errorPos = Pos;
                return 0;
            }
            get_char();
            result -= get_product();
            if (is_error())
            {
                return 0;
            }
            Skip_WhiteSpace();
        }
    }
    return result;
}


char error_message(int errorID)
{
    switch (errorID)
    {
    case ERROR_NONE:
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

void calc(const char *string)
{
    init_parse(string);
    double result = get_sum();
    if (is_error())
    {
        error_message(errorID);
        printf(" at position %d\n", errorPos+1);
        printf("%s\n", string);
        for (int i = 0; i < errorPos; i++)
        {
            printf(" ");
        }
        printf("^\n");
        return;
    }
    printf("%f\n", result);
}

int main()
{
    
    calc("5+5");
    calc("5.2+5.2");
    calc("2.3 + 1.5");

    return 0;
}