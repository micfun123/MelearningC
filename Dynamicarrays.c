#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DArray
{
    int ListSize;
    int *ListData;
};

void init(struct DArray *inputlist)
{
    inputlist->ListSize = 0;
    inputlist->ListData = NULL;
}

void append(struct DArray *inputlist, int value)
{
    inputlist->ListSize++;
    inputlist->ListData = realloc(inputlist->ListData, inputlist->ListSize * sizeof(int));
    inputlist->ListData[inputlist->ListSize - 1] = value;
}

int delete(struct DArray *inputlist, int index)
{
    if (index > inputlist->ListSize)
    {
        printf("Index out of range\n");
        return -1;
    }
    for (int i = index; i < inputlist->ListSize; i++)
    {
        inputlist->ListData[i] = inputlist->ListData[i + 1];
    }
    inputlist->ListSize--;
    inputlist->ListData = realloc(inputlist->ListData, inputlist->ListSize * sizeof(int));
    return 0;
}

int replace(struct DArray *inputlist, int index, int value)
{
    if (index > inputlist->ListSize)
    {
        printf("Index out of range\n");
        return -1;
    }
    inputlist->ListData[index] = value;
    return 0;
}

void destroy_list(struct DArray *inputlist)
{
    free(inputlist->ListData);
    inputlist->ListData = NULL;
    inputlist->ListSize = 0;
}

void insert(struct DArray *inputlist, int index, int value)
{
    inputlist->ListSize++;
    inputlist->ListData = realloc(inputlist->ListData, inputlist->ListSize * sizeof(int));
    for(int i = inputlist->ListSize; i > index; i--)
    {
        inputlist->ListData[i] = inputlist->ListData[i - 1];
    }
    inputlist->ListData[index] = value;

}

void main()
{
    struct DArray things = {0, NULL};
    append(&things, 1);
    append(&things, 2);
    append(&things, 3);
    append(&things, 4);
    for (int i = 0; i < things.ListSize; i++)
    {
        printf("%d\n", things.ListData[i]);
    }
    printf("-----------------\n");
    insert(&things, 2, 5);
    for (int i = 0; i < things.ListSize; i++)
    {
        printf("%d\n", things.ListData[i]);
    }
}