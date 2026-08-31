// 3.1 Factorial of a Number
// Write a recursive C program to compute the factorial of a non-negative integer n, defined as n! = n × (n-1) × (n-2) × ... × 1, with 0! = 1.

#include <stdio.h>

// Function to compute factorial recursively
int factorial(int n)
{
    if (n == 0 || n == 1) // Base case: factorial of 0 or 1 is 1
        return 1;
    else
        return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
}

int main()
{
    int n;

    printf("Enter a non-negative number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers.");
    else
        printf("Factorial of %d = %d", n, factorial(n));

    return 0;
}