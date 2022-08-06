#include <stdio.h>
float c;
float result;

float contof(float temp){
    float f = (temp * 9/5) + 32;
    return f;
    }

int main(){

    printf("Ener a C temp to be turn to F: ");
    scanf("%f",&c);
    result = contof(c);
    printf("%f is the temp in f", result);
}

