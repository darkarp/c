
#include <stdio.h>
#include "memaux.h"

int main()
{
    // Declaring new List
    List list = {
        .ptr = NULL,
        .real_size = 0,
        .total_size = 0};

    for (int i = 0; i < 5; i++)
    {
        append(&list, i); // Adding new valued to List
        printf("Real size: %d | Total size: %d\n", list.real_size, list.total_size);
    }

    // Printing the List
    for (int i = 0; i < list.real_size; i++)
    {
        printf("%d\n", list.ptr[i]);
    }

    printf("Old size: %d\n", list.real_size);

    printf("Popped element: %d\n", pop(&list, 0)); // Removing element from List at index
    printf("Popped element: %d\n", pop(&list, 1)); // Removing element from List at index

    printf("New size: %d\n", list.real_size);

    for (int i = 0; i < list.real_size; i++)
    {
        printf("%d\n", list.ptr[i]);
    }
    free(list.ptr);
}
