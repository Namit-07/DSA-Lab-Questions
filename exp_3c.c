// 3.3 Tower of Hanoi 
// Write a recursive C program to solve the Tower of Hanoi puzzle for n disks: move all disks from a source rod to a destination rod, using an auxiliary rod, such that a larger disk is never placed on a smaller one, only the top disk of a rod can be moved and only one disk is moved at a time. 


// 
#include <stdio.h>

// Function to solve Tower of Hanoi puzzle recursively
void towerOfHanoi(int n, char source, char auxiliary, char destination) 
{ 
    if (n == 1) // Base case: only one disk to move 
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Recursive case: move n-1 disks from source to auxiliary, then move the nth disk to destination, and finally move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0)
        printf("Number of disks must be positive.");
    else
        towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}