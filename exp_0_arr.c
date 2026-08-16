// Experiment 0 Array Operations Pointers
// Programs based on 2-D array operations with pointer notation

#include <stdio.h>
#define ROWS 3
#define COLS 3
void printArray(int (*arr)[COLS], int rows, int cols)
{
    printf("Array elements:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d ", *((*(arr + i)) + j)); // Using pointer notation to access and print array elements
        }
        printf("\n");
    }
}
void multiplyByTwo(int (*arr)[COLS], int rows, int cols)
{
    printf("Array elements multiplied by 2:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            *((*(arr + i)) + j) *= 2; // Using pointer notation to multiply each element by 2
            printf("%d ", *((*(arr + i)) + j));
        }
        printf("\n");
    }
}
int main()
{
    int arr[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    // Using pointer notation to access and print array elements
    printArray(arr, ROWS, COLS);
    // Using pointer notation to multiply each element by 2
    multiplyByTwo(arr, ROWS, COLS);
    return 0;
    }
