#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data; // Assign the data to the new node
    newNode->left = NULL; // Initialize left child to NULL
    newNode->right = NULL; // Initialize right child to NULL

    return newNode;
}

// In-order Traversal: Left -> Root -> Right
void inorder(struct Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Pre-order Traversal: Root -> Left -> Right
void preorder(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Post-order Traversal: Left -> Right -> Root
void postorder(struct Node* node) {
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main() {

    // Constructing the binary tree
    //
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5

    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Display traversals
    printf("In-order Traversal: ");
    inorder(root);
    printf("\nPre-order Traversal: ");
    preorder(root);

    printf("\nPost-order Traversal: ");
    postorder(root);

    return 0;
}