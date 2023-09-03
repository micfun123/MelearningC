#include <stdio.h>
#include <stdbool.h>

int suduku_board[9][9];

void load_board()
{
    FILE *fp;
    fp = fopen("matrix.txt", "r");
    int i, j;
    // allow a . for a blank space
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            fscanf(fp, "%d", &suduku_board[i][j]);
        }
    }
    fclose(fp);
}

void print_board()
{
    int i, j;
    printf("\n");
    for (i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            printf("-------------------------\n");
        }
        for (j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                printf("| ");
            }
            printf("%d ", suduku_board[i][j]);
        }
        printf("|\n");
    }
    printf("-------------------------\n");
}

bool check_row(int row)
{
    int buffer[9];
    for (int i = 0; i < 9; i++)
    {
        if (suduku_board[row][i] == 0)
        {
            return false;
        }
        else
        {
            buffer[i] = suduku_board[row][i];
        }
    }
    // check for duplicates
    int is_duplicate = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (buffer[i] == buffer[j])
            {
                is_duplicate = 1;
            }
        }
    }
    if (is_duplicate == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    load_board();
    print_board();
    check_row(0);
    return 0;
}