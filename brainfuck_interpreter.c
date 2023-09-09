#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char brainfuck_memory[1000] = {0};
char BF_IN[] = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.";
int place = 0;
int current = 0;
int cell = 0;

bool End_of_String()
{
    return !(place < strlen(BF_IN));
}

char get_char()
{
    if (End_of_String())
        return 0;
    return BF_IN[place++];
}

char peek_char()
{
    if (End_of_String())
        return 0;
    return BF_IN[place];
}

void parser()
{
    // Loop stack to keep track of loop positions
    int loop_stack[1000];
    // Current loop depth
    int loop_depth = 0;

    while (!End_of_String())
    {
        if (peek_char() == '>')
        {
            cell++;
            current = 0;
            get_char();
        }
        else if (peek_char() == '<')
        {
            cell--;
            current = 0;
            get_char();
        }
        else if (peek_char() == '+')
        {
            brainfuck_memory[cell]++;
            get_char();
        }
        else if (peek_char() == '-')
        {
            brainfuck_memory[cell]--;
            get_char();
        }
        else if (peek_char() == '.')
        {
            putchar(brainfuck_memory[cell]);
            get_char();
        }
        else if (peek_char() == ',')
        {
            printf("Enter a Char: ");
            int input_char = getchar();
            brainfuck_memory[cell] = input_char;
            get_char();
        }
        else if (peek_char() == '[')
        {
            if (brainfuck_memory[cell] == 0)
            {
                int skip_loops = 1;
                while (skip_loops > 0)
                {
                    get_char();
                    if (peek_char() == '[')
                        skip_loops++;
                    else if (peek_char() == ']')
                        skip_loops--;
                }
            }
            else
            {
                loop_stack[loop_depth] = place;
                loop_depth++;
                get_char();
            }
        }
        else if (peek_char() == ']')
        {
            if (brainfuck_memory[cell] != 0)
            {
                place = loop_stack[loop_depth - 1];
            }
            else
            {
                loop_depth--;
                get_char();
            }
        }
        else
        {
            place++;
            printf("\n Invalid character %c at pos %d\n", peek_char(), place + 1);
            return;
        }
    }
}

int main()
{
    parser();
    return 0;
}
