// (c) Finding the Maximum element

#include <stdio.h>
#define SIZE 3 // size of the array

int main(){
    int arr[SIZE] = {10, 20, 30}; // Initializing the array
    int max = arr[0]; // Initializing the maximum element

    // Finding the maximum element
    for(int i = 0; i < SIZE; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("Maximum element is: %d\n", max); // Printing the maximum element
    return 0;
}