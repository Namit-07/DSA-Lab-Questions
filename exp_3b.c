// 3.2 Fibonacci Series
// Write a recursive C program to compute the nth term of the Fibonacci series, defined as F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.

#include <stdio.h>

int fibonacci(int n)
{ 
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0)
        return 0;
    else if (n == 1) // Base case: F(1) = 1
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case: F(n) = F(n-1) + F(n-2)
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Fibonacci term is not defined for negative numbers.");
    else
        printf("The %dth Fibonacci term is %d", n, fibonacci(n));

    return 0;
}