#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int key) {

    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// In-order traversal
void inorder(struct Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    struct Node* root = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("BST (in-order, sorted): ");
    inorder(root);

    return 0;
}