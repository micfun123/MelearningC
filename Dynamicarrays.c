#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct DArray{
    int ListSize;
    int *ListData;
};

void add(struct DArray *inputlist, int value){
    inputlist->ListData = realloc(inputlist->ListData, inputlist->ListSize + 1 * sizeof(int));
    inputlist->ListData[inputlist->ListSize] = value;
    inputlist->ListSize++;
    
}

void init(struct DArray *inputlist){
    inputlist->ListSize = 0;
    inputlist->ListData = NULL;
}

int append(struct DArray *inputlist, int index,int value){
    if (index > inputlist->ListSize){
        printf("Index out of range\n");
        return -1;
    }
    inputlist->ListData[index] = value;
    return 0;
}

void main(){
    struct  DArray things;
    init(&things);
    add(&things, 1);
    add(&things, 2);
    add(&things, 3);
    append(&things, 10, 5);

    for(int i = 0; i < things.ListSize; i++){
        printf("%d\n", things.ListData[i]);
    }


}