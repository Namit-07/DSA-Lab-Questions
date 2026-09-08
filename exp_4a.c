// 4.1 Priority Queue Using an Unsorted Array
// Implement a max-priority queue in C using an unsorted array, supporting insert, extractMax, and peek operations.

#include <stdio.h>

#define MAX 100 // Maximum size of the priority queue

// Structure to represent an element in the priority queue
struct Element
{
    int data;
    int priority;
};

// Global variables for the priority queue
struct Element pq[MAX];
int size = 0;

// Function to insert an element into the priority queue
void insert(int data, int priority)
{
    if (size == MAX)
    {
        printf("Priority Queue is full.\n");
        return;
    }

// Insert the new element at the end of the array
    pq[size].data = data;
    pq[size].priority = priority;
    size++;

    printf("Element inserted successfully.\n");
}

// Function to extract the element with the highest priority
void extractMax()
{
    if (size == 0)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    int maxIndex = 0; // Initialize maxIndex to the first element

    // Find the element with highest priority
    for (int i = 1; i < size; i++)
    {
        if (pq[i].priority > pq[maxIndex].priority) // Compare priorities
        {
            maxIndex = i; // Update maxIndex if a higher priority is found
        }
    }

    printf("Extracted element: %d\n", pq[maxIndex].data);

    // Shift elements to fill the empty position
    for (int i = maxIndex; i < size - 1; i++) // Shift elements to the left
    {
        pq[i] = pq[i + 1]; // Move the next element to the current position
    }

    size--; // Decrease the size of the priority queue
}

// Function to peek at the element with the highest priority without removing it
void peek()
{
    if (size == 0)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    int maxIndex = 0;

    // Find highest-priority element
    for (int i = 1; i < size; i++)
    {
        if (pq[i].priority > pq[maxIndex].priority) // Compare priorities
        {
            maxIndex = i;
        }
    }

    printf("Highest priority element: %d\n", pq[maxIndex].data);
    printf("Priority: %d\n", pq[maxIndex].priority);
}

// Function to display all elements in the priority queue
void display()
{
    if (size == 0)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nElements in Priority Queue:\n");

    for (int i = 0; i < size; i++)
    {
        printf("Data: %d, Priority: %d\n",
               pq[i].data, pq[i].priority); // Display each element's data and priority
    }
}

int main()
{
    int choice, data, priority;

    while (1)
    {
        printf("\n--- Priority Queue Using Unsorted Array ---\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);

                printf("Enter priority: ");
                scanf("%d", &priority);

                insert(data, priority);
                break;

            case 2:
                extractMax();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}