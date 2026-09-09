// 4.2 Priority Queue Using a Sorted Linked List
// Implement a max-priority queue in C using a singly linked list kept in descending order of priority, supporting insert, extractMax, and peek operations.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

// Global variable for the head of the linked list
struct Node *head = NULL;

// Function to insert an element into the priority queue
void insert(int data, int priority)
{
    struct Node *newNode; // Declare a pointer for the new node
    struct Node *temp; // Declare a pointer for traversing the list

    newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node

    // Initialize the new node's data and priority
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    // Insert at beginning if list is empty
    // or new node has highest priority
    if (head == NULL || priority > head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;

        // Find correct position
        while (temp->next != NULL &&
               temp->next->priority >= priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element inserted successfully.\n");
}

// Function to extract the maximum priority element
void extractMax()
{
    if (head == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Extracted element: %d\n", head->data);
    printf("Priority: %d\n", head->priority);

    head = head->next;

    free(temp);
}

// Function to peek at the maximum priority element without removing it
void peek()
{
    if (head == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Highest priority element: %d\n", head->data);
    printf("Priority: %d\n", head->priority);
}

// Function to display all elements in the priority queue
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nElements in Priority Queue:\n");

    while (temp != NULL)
    {
        printf("Data: %d, Priority: %d\n",
               temp->data, temp->priority);

        temp = temp->next;
    }
}

int main()
{
    int choice, data, priority;

    while (1)
    {
        printf("\n--- Priority Queue Using Sorted Linked List ---\n");
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