#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Given an in array with size's size and rotates as the amount of rotates to make,
 * return out array with the array rotate left
 * */
void array_rotate_left (int *in, int size, int rotates, int *out){
    int *temp;

    temp = (int *) malloc(sizeof(int) * rotates);
    memcpy(temp, in, sizeof(int) * rotates);    // create a temp array with rotates'n elements to be added after
    memcpy(out, &in[rotates], sizeof(int) * (size - rotates));
    memcpy(&out[(size - rotates)], temp, sizeof(int) * rotates);

    free(temp);
}

void main (void){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int out[10] = {0};
    int amount = (sizeof(arr) / sizeof(arr[0]));
    int times_to_rotate = 3;

    array_rotate_left(arr, amount, times_to_rotate, out);
    
    printf("in: ");
    for (int i = 0; i < amount; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("times to rotate: %d\n", times_to_rotate);

    printf("out (left rotation): ");
    for (int i = 0; i < amount; i++){
        printf("%d", out[i]);
    }
    printf("\n");

    exit(0);
}