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

void init_board()
{
    load_board();
    print_board();
}

int next_empty(int *row, int *column)
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*column = 0; *column < 9; (*column)++)
        {
            if (suduku_board[*row][*column] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
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

bool check_column(int column)
{
    int buffer[9];
    for (int i = 0; i < 9; i++)
    {
        if (suduku_board[i][column] == 0)
        {
            return false;
        }
        else
        {
            buffer[i] = suduku_board[i][column];
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

bool check_cube(int cube)
{
    int buffer[9];
    int row = cube / 3;
    int column = cube % 3;
    int index = 0;
    for (int i = row * 3; i < row * 3 + 3; i++)
    {
        for (int j = column * 3; j < column * 3 + 3; j++)
        {
            if (suduku_board[i][j] == 0)
            {
                return false;
            }
            else
            {
                buffer[index] = suduku_board[i][j];
                index++;
            }
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

bool check_board()
{
    for (int i = 0; i < 9; i++)
    {
        if (check_row(i) == false)
        {
            return false;
        }
        if (check_column(i) == false)
        {
            return false;
        }
        if (check_cube(i) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    init_board();
    if (check_board() == true)
    {
        printf("Board is valid\n");
    }
    else
    {
        printf("Board is invalid\n");
    }

    return 0;
}