#include <stdio.h>

struct qurds {
    char data;
    int next;
};

struct qurds locations[100] = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', -1}};

int read(int index)
{
    return locations[index].data;
}

int next(int index)
{
    return locations[index].next;
}


int add(int index, char data)
{
    int count = 0;
    while (locations[count].next != -1) {
        count++;
    }
    locations[count].data = data;
    locations[count].next = index;
    return count;
}

int main()
{
    int index = 0;
    while (index != -1) {
        printf("%c\n", read(index));
        index = next(index);
    }
    printf("Adding f to the list\n");
    index = add(index, 'f');
    while (index != -1) {
        printf("%c\n", read(index));
        index = next(index);
    }
    return 0;
}