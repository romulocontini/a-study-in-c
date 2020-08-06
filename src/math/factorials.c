#include <stdlib.h>
#include <stdio.h>

/* Use recursion to calculate the factorial of a given integer */
int factorial (int x){
    if (x == 1){
        return 1;
    } else{
        return x * factorial(x - 1);
    }
}

void main (void){
    printf("5!: %d\n", factorial(5));
    printf("10!: %d\n", factorial(10));

    exit(0);
}
