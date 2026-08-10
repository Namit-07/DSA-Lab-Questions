// (b) Finding the Sum

#include <stdio.h>
#define SIZE 3 // size of the array

int main(){
    int arr[SIZE] = {10, 20, 30}; // Initializing the array
    int sum = 0; // Variable to store the sum of array elements

    // Calculating the sum of array elements
    for(int i = 0; i < SIZE; i++){
        sum += arr[i];
    }

    printf("Sum of array elements is: %d\n", sum); // Printing the sum
    return 0;
}