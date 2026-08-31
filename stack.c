#include <stdio.h>
#include <stdlib.h> // for malloc
#include <string.h> // for string operations

int main() {
    int n, top = -1; // top is initialized to -1 to indicate an empty stack

    printf("Enter number of books: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    char **stack = (char **)malloc(n * sizeof(char *)); // Allocate memory for n pointers to char

    // Push books
    for (int i = 0; i < n; i++) {
        stack[++top] = (char *)malloc(50 * sizeof(char)); // Allocate memory for each book title 

        printf("Enter book %d: ", i + 1);
        scanf(" %[^\n]", stack[top]);
    }

    // Display stack
    printf("\nBooks in stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }

    // Pop
    printf("\nPopped book: %s\n", stack[top]);

    // Free memory for the popped book
    free(stack[top]);
    top--;

    // Display after pop
    printf("\nStack after pop:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }

    // Free remaining memory
    for (int i = 0; i <= top; i++) {
        free(stack[i]);
    }

    free(stack);

    return 0;
}