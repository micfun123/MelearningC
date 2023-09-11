#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char brainfuck_memory[30000] = {0};
int place = 0;
int current = 0;
int cell = 0;

bool End_of_String(char* code)
{
    return !(place < strlen(code));
}

char get_char(char* code)
{
    if (End_of_String(code))
        return 0;
    return code[place++];
}

char peek_char(char* code)
{
    if (End_of_String(code))
        return 0;
    return code[place];
}

void parser(char* code)
{
    // Loop stack to keep track of loop positions
    int loop_stack[1000];
    // Current loop depth
    int loop_depth = 0;

    while (!End_of_String(code))
    {
        if (peek_char(code) == '>')
        {
            cell++;
            current = 0;
            get_char(code);
        }
        else if (peek_char(code) == '<')
        {
            cell--;
            current = 0;
            get_char(code);
        }
        else if (peek_char(code) == '+')
        {
            brainfuck_memory[cell]++;
            get_char(code);
        }
        else if (peek_char(code) == '-')
        {
            brainfuck_memory[cell]--;
            get_char(code);
        }
        else if (peek_char(code) == '.')
        {
            putchar(brainfuck_memory[cell]);
            get_char(code);
        }
        else if (peek_char(code) == ',')
        {
            printf("Enter a Char: ");
            int input_char = getchar();
            brainfuck_memory[cell] = input_char;
            get_char(code);
        }
        else if (peek_char(code) == '[')
        {
            if (brainfuck_memory[cell] == 0)
            {
                int skip_loops = 1;
                while (skip_loops > 0)
                {
                    get_char(code);
                    if (peek_char(code) == '[')
                        skip_loops++;
                    else if (peek_char(code) == ']')
                        skip_loops--;
                }
            }
            else
            {
                loop_stack[loop_depth] = place;
                loop_depth++;
                get_char(code);
            }
        }
        else if (peek_char(code) == ']')
        {
            if (brainfuck_memory[cell] != 0)
            {
                place = loop_stack[loop_depth - 1];
            }
            else
            {
                loop_depth--;
                get_char(code);
            }
        }
        else
        {
            place++;
            printf("\n Invalid character %c at pos %d\n", peek_char(code), place + 1);
            return;
        }
    }
}

int main(int argc, char *argv[]) 
{   
    if (argc != 2)
    {
        printf("Usage: %s <Brainfuck code>\n", argv[0]);
        return 1;
    }

    char* code = argv[1];
    parser(code);
    return 0;
}
