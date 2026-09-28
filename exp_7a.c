#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Stack
struct Node* stack[MAX];
int top = -1;

// Push a node onto the stack
void push(struct Node* node) {
    stack[++top] = node;
}

// Pop a node from the stack
struct Node* pop() {
    return stack[top--];
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Iterative In-order
void inorder(struct Node* root) {
    struct Node* curr = root;

    while (curr != NULL || !isEmpty()) {

        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }

        curr = pop();

        printf("%d ", curr->data);

        curr = curr->right;
    }
}

// Iterative Pre-order
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    push(root);

    while (!isEmpty()) {
        struct Node* curr = pop();

        printf("%d ", curr->data);

        if (curr->right != NULL)
            push(curr->right);

        if (curr->left != NULL)
            push(curr->left);
    }
}

// Iterative Post-order
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[MAX];
    struct Node* stack2[MAX];

    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* curr = stack1[top1--];

        stack2[++top2] = curr;

        if (curr->left != NULL)
            stack1[++top1] = curr->left;

        if (curr->right != NULL)
            stack1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
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

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order Traversal: ");
    inorder(root);

    printf("\nPre-order Traversal: ");
    top = -1;
    preorder(root);

    printf("\nPost-order Traversal: ");
    postorder(root);

    return 0;
}