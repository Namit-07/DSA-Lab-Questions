// 5.2 C Program for Array Representation 

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node

    newNode->data = value; // Assign the value to the node
    newNode->left = NULL; // Initialize left child to NULL
    newNode->right = NULL; // Initialize right child to NULL

    return newNode;
}

int main()
{
    // Create nodes
    struct Node* root = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);
    struct Node* node6 = createNode(6);

    // Link the nodes
    root->left = node2;
    root->right = node3;

    // Children of node 2
    node2->left = node4; 
    node2->right = node5;

    // Children of node 3
    node3->left = NULL;
    node3->right = node6;

    printf("Binary Tree using Linked Representation:\n\n");

    printf("Root: %d\n", root->data);

    printf("Left child of root: %d\n",
           root->left->data);

    printf("Right child of root: %d\n",
           root->right->data);

    printf("Left child of node 2: %d\n",
           root->left->left->data);

    printf("Right child of node 2: %d\n",
           root->left->right->data);

    printf("Right child of node 3: %d\n",
           root->right->right->data);

    // Free allocated memory
    free(node4);
    free(node5);
    free(node6);
    free(node2);
    free(node3);
    free(root);

    return 0;
}