#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node *insert(struct Node *root, int val)
{
    if (root == NULL)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        printf("Duplicate value %d ignored.\n", val);
    return root;
}

struct Node *search(struct Node *root, int key)
{
    while (root != NULL && root->data != key)
        root = (key < root->data) ? root->left : root->right;
    return root;
}

struct Node *leftmost(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *delete(struct Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *succ = leftmost(root->right);
        root->data = succ->data;
        root->right = delete(root->right, succ->data);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;
    int choice, val;

    while (1)
    {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Inorder\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
            {
                char line[256];
                char *p = line;
                int n;
                printf("Enter value(s) to insert: ");
                scanf(" %255[^\n]", line);
                while (sscanf(p, "%d%n", &val, &n) == 1)
                {
                    root = insert(root, val);
                    p += n;
                }
                break;
            }
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("%d found in BST.\n", val);
            else
                printf("%d not found.\n", val);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            if (search(root, val) == NULL)
                printf("%d not found.\n", val);
            else
            {
                root = delete(root, val);
                printf("%d deleted.\n", val);
            }
            break;
        case 4:
            printf("In-order: ");
            if (root == NULL)
                printf("(empty)");
            else
                inorder(root);
            printf("\n");
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}