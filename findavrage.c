#include <stdio.h>

struct qurds {
    int x;
    int y;
    int islast;
};

//make a array of qurds
struct qurds locations[] = {{30,20,0}, {1,10,0}, {2,33,0}, {30,32,0}, {4,43,1}};


int main()
{
    int sumx = 0;
    int sumy = 0;
    int count = 0;
    while (locations[count].islast != 1) {
        sumx += locations[count].x; //add the x and y to the sum
        sumy += locations[count].y;
        count++;
    }
    int avrage_x = sumx / count; //find the avrage
    int avrage_y = sumy / count;
    printf("The avrage x is %d and the avrage y is %d\n", avrage_x, avrage_y);
    return 0;
}
