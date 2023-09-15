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

void add(struct DArray *inputlist, int value)
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

int append(struct DArray *inputlist, int index, int value)
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

void main()
{
    struct DArray things = {0, NULL};
    add(&things, 1);
    add(&things, 2);
    add(&things, 3);
    add(&things, 4);
    for (int i = 0; i < things.ListSize; i++)
    {
        printf("%d\n", things.ListData[i]);
    }
    printf("-----------------\n");
    destroy_list(&things);
    add(&things, 5);
    add(&things, 6);
    add(&things, 7);
    for (int i = 0; i < things.ListSize; i++)
    {
        printf("%d\n", things.ListData[i]);
    }
}