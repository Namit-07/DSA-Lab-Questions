// 5.1 C Program for Array Representation 

#include <stdio.h>

#define SIZE 7

int main()
{
    int tree[SIZE] = {-1, -1, -1, -1, -1, -1, -1};

    // Root
    tree[0] = 1;

    // Left and right children of root
    tree[1] = 2;
    tree[2] = 3;

    // Children of node 2
    tree[3] = 4;
    tree[4] = 5;

    // Node 3 has no left child
    tree[5] = -1;

    // Right child of node 3
    tree[6] = 6;

    printf("Binary Tree using Array Representation:\n\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d : %d\n", i, tree[i]);
    }

    return 0;
}