#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

size_t Pos;
const char* string;
int result;

void init_parse(const char in_string[]){
    Pos = 0;
    string = in_string;

}

//future function ideas whitespace, peeks at the char if white space then we get character and then breaks at a none whitespace

bool End_of_String(){
    return !(Pos < strlen(string));
}

char get_char(){
    //check if there are chars left to read else return 0. Makes it safe
    if (End_of_String()) return 0;
    // gets the current byte (char) then moves the Pos falwards by one 
    return string[Pos++];
    
}

char peek_char(){ 
    //check if there are chars left to read else return 0. Makes it safe
    if (End_of_String()) return 0;
    // looks at the current byte (char) with out moving falwards
    return string[Pos];
}

void Skip_WhiteSpace(){
    while (peek_char() == ' ')
    {
        Pos++;
    }
    
}

bool allowed_digit(char c){
    //0-9 + - * / ( )
    return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

char get_digit(){
    Skip_WhiteSpace();
    //find the next allowed digit
    char c = get_char();
    while (!allowed_digit(c))
    {
        Skip_WhiteSpace();
        c = get_char();
    }
    return c;
}

char calc(const char Equation[]){
    init_parse(Equation);
    while (!End_of_String())
    {
        printf("Next char: %c\n", get_digit());
    }
     
}



int main(){
    char myString[] = "    a       1+1       v     * 2           ";
    calc(myString);
    
    return 0;
}