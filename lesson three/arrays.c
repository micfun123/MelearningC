/* Prints a message on the screen */
#include <stdio.h>

int othernum[] = {10, 20, 30, 40,50,60,70,80,90,100};

int main(){ 
   // array inside of main
  int myNumbers[] = {1, 2, 3, 4,5,6,7,8,9,10};
  printf("%d\n", myNumbers[3]);
  printf("%d\n", othernum[7]);
  myNumbers[3] = 6;
  printf("%d\n", myNumbers[3]);
 
  return 0;
}