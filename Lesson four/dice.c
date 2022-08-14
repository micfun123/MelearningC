#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* dice [] = {
"-----\n"
"|   |\n"
"| o |\n"
"|   |\n"
"-----\n"
,
"-----\n"
"|o  |\n"
"|   |\n"
"|  o|\n"
"-----\n"
,
"-----\n"
"|o  |\n"
"| o |\n"
"|  o|\n"
"-----\n"
,
"-----\n"
"|o o|\n"
"|   |\n"
"|o o|\n"
"-----\n"
,
"-----\n"
"|o o|\n"
"| o |\n"
"|o o|\n"
"-----\n"
,
"-----\n"
"|o o|\n"
"|o o|\n"
"|o o|\n"
"-----\n"
};

int random(){
   return rand() % 7;
}


int main(){
    srand(time(NULL));
    int num;
    num = random();
    printf("%d\n",num);
    printf("%s\n",dice[num]);
    return 0;
     
}

