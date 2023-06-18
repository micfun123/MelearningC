#include <stdio.h>
#include <stdint.h>

void main(){
    uint64_t a = 0;
    uint64_t b = 0;
    uint64_t z = 0;
    uint64_t total = 0;
    uint64_t amount = 0;

    printf("What should be the starting number: ");
    scanf("%d",&b);
    printf("How many places should we go up: ");
    scanf("%d",&amount);

    for (uint64_t i = 0; i < amount; i++)
    {
        z = a + b;
        total = total + z;
        printf("%d ",z);
        a = b;
        b = z;
    }
    printf("\n your total is %d \n",total);
}