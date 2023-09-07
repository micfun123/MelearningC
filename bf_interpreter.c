#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for strlen()

//brain fuck interpreter
unsigned char brainfuck_memory[1000] = {0};
char BF_IN[] = ">++++++++-.";
//">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.";
int place = 0;
int current = 0;
int cell = 0;

bool End_of_String()
{
    return !(place < strlen(BF_IN));
}


char get_char()
{
    // check if there are chars left to read else return 0. Makes it safe
    if (End_of_String())
        return 0;
    // gets the current byte (char) then moves the Pos falwards by one
    return BF_IN[place++];
}

char peek_char()
{
    // check if there are chars left to read else return 0. Makes it safe
    if (End_of_String())
        return 0;
    // looks at the current byte (char) with out moving falwards
    return BF_IN[place];
}

void parser()
{
    while (!End_of_String()){
        if (peek_char()=='>')
        {
            //add it to array
            cell++;
            current =0;
            get_char();
        }
        else if (peek_char()=='<')
        {
            cell--;
            current =0;
            get_char();
        }
        else if (peek_char()=='+')
        {
            current++;
            brainfuck_memory[cell] = current;
            get_char();

        }else if (peek_char()=='-')
        {
            current--;
            brainfuck_memory[cell] = current;
            get_char();
        }
        else if (peek_char()=='.')
        {
            printf("%d",current);
            get_char();
        }else if (peek_char() == ',') 
        {
            printf("Enter a Char: ");
            // Read a character from input
            int input_char = getchar();

            // Store its ASCII value in the current memory cell
            brainfuck_memory[cell] = input_char;

            get_char();
        }else if(peek_char()=='[')
        {
            if (current==0)
            {
                while (peek_char()!=']')
                {
                    place++;
                }
            }
            else
            {
                place++;
            }
        }
        else
        {
            place++;
            printf("\n Invalid character %c\n",peek_char());
            return;
        }
        
    }

}

void main()
{
    parser();
}