#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

size_t Pos;
const char* string;

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

bool is_digit(char c){
    return (c >= '0' && c <= '9');
}

char calc(const char Equation[]){
    init_parse(Equation);
    while (!End_of_String())
    {   
        Skip_WhiteSpace();
        if (is_digit(peek_char()))
        {
            printf("%c",get_char());
        }
    }
     
}



int main(){
    char myString[] = "           1+1            * 2           ";
    calc(myString);
    
    return 0;
}