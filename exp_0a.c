// Array Operations 1 (Programs based on 1D array operations)

// (a) Initialization
#include <stdio.h>
#define SIZE 3 // size of the array

int main(){
    int arr[SIZE] = {10, 20, 30}; // Intializing the array
    printf("Array elements are:\n"); // Printing the array elements
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}