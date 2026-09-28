#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    // 1 if right pointer is a thread
    // 0 if right pointer points to a real child
    int rightThread;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->rightThread = 1;

    return newNode;
}

// Find the leftmost node
struct Node* leftmost(struct Node* node) {
    if (node == NULL)
        return NULL;

    while (node->left != NULL)
        node = node->left;

    return node;
}

// In-order traversal of threaded binary tree
void inorderThreaded(struct Node* root) {

    struct Node* curr = leftmost(root);

    while (curr != NULL) {

        printf("%d ", curr->data);

        if (curr->rightThread == 1) {
            // Follow the thread
            curr = curr->right;
        }
        else {
            // Move to leftmost node
            // of right subtree
            curr = leftmost(curr->right);
        }
    }
}

int main() {

    /*
             1
            / \
           2   3
          / \
         4   5
    */

    struct Node* root = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);

    root->left = node2;
    root->right = node3;
    root->rightThread = 0;

    node2->left = node4;
    node2->right = node5;
    node2->rightThread = 0;

    // Create threads
    node4->right = node2;
    node4->rightThread = 1;

    node5->right = root;
    node5->rightThread = 1;

    node3->right = NULL;
    node3->rightThread = 1;

    printf("In-order Traversal of Threaded Binary Tree: ");

    inorderThreaded(root);

    return 0;
}