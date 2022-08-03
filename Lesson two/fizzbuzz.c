#include <stdio.h>

int x;

int main(){

    printf("Enter a positive int: \n");
    scanf("%d", &x);

    if (x % 3 == 0 && x % 5 == 0){
        printf("FizzBuzz");

    } else if (x % 3 == 0)
    {
        printf("buzz");
    }else if (x % 5 == 0)
    {
        printf("Buzz");
    }else{
        printf("%d",x);
    }
    
    return(0);
}

