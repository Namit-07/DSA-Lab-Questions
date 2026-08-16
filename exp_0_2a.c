// Experiment 0 Array Operation 2 
// Programs based on 1-D array operations

// (a)  Insert an integer in the array
#include <stdio.h> 
#define MAX_SIZE 10  // Set a maximum size for the array

int main() { 
    int arr[MAX_SIZE] = {10, 20, 30};  // Initializing the array with 3 elements
    int current_size = 3;  // Number of elements currently in the array
    int insertIndex, newValue;

    printf("Elements of the array:\n");   // Printing the elements of the array 
    for (int i = 0; i < current_size; ++i) { 
        printf("arr[%d] = %d\n", i, arr[i]); 
    }

    // Prompt the user for the index and new value to insert
    printf("Enter the index where you want to insert (0 to %d): ", current_size);  
    scanf("%d", &insertIndex); 

    if (insertIndex < 0 || insertIndex > current_size) {  
        printf("Invalid index! Please enter a valid index.\n");  
        return 1; // Exit the program with error status  
    } 
    
    printf("Enter the new value to insert: ");  
    scanf("%d", &newValue); 

    // Shift elements to the right to make space for the new value  
    for (int i = current_size; i > insertIndex; --i) {  
        arr[i] = arr[i - 1];  
    } 
    
    // Insert the new value at the specified index  
    arr[insertIndex] = newValue; 
    current_size++; // Increment the size of the array

    printf("Array after insertion:\n"); 
    for (int i = 0; i < current_size; ++i) { 
        printf("arr[%d] = %d\n", i, arr[i]); 
    } 
    
    return 0; 
} 
