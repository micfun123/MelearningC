#include <stdio.h>
int num1;
int num2;
int num3;
float result;

int main(){

    printf("Please enter a number for the first test marks: \t");
    scanf("%i", &num1);
    printf("Please enter a number for the second test marks: \t");
    scanf("%i", &num2);
    printf("Please enter a number for the thirds test marks: \t");
    scanf("%i", &num3);

    result = (num1 + num2 + num3)/3;
    printf("%.3f was the average grade", result);



    return 0;
}