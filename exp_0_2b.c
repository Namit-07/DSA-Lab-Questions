// (b) Search an element using linear search
#include <stdio.h>

int main(void)
{
    int a[10], i, item, flag = 0;

    printf("Enter 10 integer elements for the array:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &item);

    for (i = 0; i < 10; i++)
    {
        if (item == a[i])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        // We print i + 1 because arrays are 0-indexed but positions are 1-indexed.
        printf("Element Found at Position = %d\n", i);
    }
    else
    {
        printf("Element Not Found\n");
    }

    return 0;
}