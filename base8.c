#include <stdio.h>
#include <math.h>


int base(int num){
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 8) + 10 * base(floor(num/8));
    }
    
    
}

int main(){
    printf("%d \n", base(15));
    printf("%d \n", base(0));
    printf("%d \n", base(8));
    printf("%d \n", base(25));
}
