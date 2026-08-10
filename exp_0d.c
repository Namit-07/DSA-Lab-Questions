// (d) Reversing the Array

#include <stdio.h>
#define SIZE 3 // size of the array

int main(){
    int arr[SIZE] = {10, 20, 30}; // Initializing the array
    int reversed[SIZE]; // Initializing the reversed array

    // Reversing the array
    for(int i = 0; i < SIZE; i++){
        reversed[i] = arr[SIZE - i - 1];
    }

    printf("Reversed array is:\n"); // Printing the reversed array
    for(int i = 0; i < SIZE; i++){
        printf("%d ", reversed[i]);
    }
    return 0;
}   