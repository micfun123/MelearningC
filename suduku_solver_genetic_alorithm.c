#include <stdio.h>
#include <stdbool.h>

#define POPULATION_SIZE 1000


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


void init_board()
{
    load_board();
    print_board();
}


double check_row(int row)
{
    //create a score for the row where 0 is a perfect row and 1 is a row with no matches
    double score = 0;
    int buffer[9];
    for (int i = 0; i < 9; i++)
    {
        if (suduku_board[row][i] == 0)
        {
            return 1;
        }
        buffer[i] = suduku_board[row][i];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if (buffer[i] == buffer[j])
            {
                score++;
            }
        }
    }
    return score/36; //36 is the number of possible matches in a row of 9 due to 9*8/2
}

double check_column(int column)
{
    //create a score for the column where 0 is a perfect column and 1 is a column with no matches
    double score = 0;
    int buffer[9];
    for (int i = 0; i < 9; i++)
    {
        if (suduku_board[i][column] == 0)
        {
            return 1;
        }
        buffer[i] = suduku_board[i][column];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if (buffer[i] == buffer[j])
            {
                score++;
            }
        }
    }
    return score/36; //36 is the number of possible matches in a column of 9 due to 9*8/2
}

double check_square(int row, int column)
{
    //create a score for the square where 0 is a perfect square and 1 is a square with no matches
    double score = 0;
    int buffer[9];
    int row_start = row - row % 3;
    int column_start = column - column % 3;
    for (int i = row_start; i < row_start + 3; i++)
    {
        for (int j = column_start; j < column_start + 3; j++)
        {
            if (suduku_board[i][j] == 0)
            {
                return 1;
            }
            buffer[i] = suduku_board[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if (buffer[i] == buffer[j])
            {
                score++;
            }
        }
    }
    return score/36; //we get 36 from 9*8/2 where 9 is the number of squares and 8 is the number of possible matches in a square of 9
}

double check_board()
{
    //create a score for the board where 0 is a perfect board and 1 is a board with no matches
    double score = 0;
    for (int i = 0; i < 9; i++)
    {
        score += check_row(i);
        score += check_column(i);
    }
    for (int i = 0; i < 9; i+=3)
    {
        for (int j = 0; j < 9; j+=3)
        {
            score += check_square(i, j);
        }
    }
    return score/27; // we get 27 from 9*3 where 9 is the number of rows, columns, and squares and 3 is the number of checks per row, column, and square

}



int main()
{
    init_board();
    check_board();
    printf("%f", check_row(0));
    return 0;
}