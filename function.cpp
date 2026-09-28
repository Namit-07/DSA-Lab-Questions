#include "stack111.h"

int main()
{
    linkedlist<int> numbers;
    numbers.insert_end(10);
    numbers.insert_end(20);
    numbers.insert_beg(5);
    numbers.insert_after(15, 10);
    numbers.display();

    numbers.reverse();
    numbers.display();

    return 0;
}