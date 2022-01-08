
#include <stdio.h>
#include "memaux.h"

int main()
{
    // Declaring new List
    List list = {
        .ptr = NULL,
        .real_size = 0,
        .total_size = 0};

    printf("Appending to the list:\n");

    for (int i = 0; i < 10; i++)
    {
        append(&list, i); // Adding new valued to List
        printf("Real size: %d | Total size: %d\n", list.real_size, list.total_size);
    }

    // Printing the List

    printf("List after appending:\n");
    for (int i = 0; i < list.real_size; i++)
    {
        printf("%d\n", list.ptr[i]);
    }

    printf("\nPopping elements at index %d and %d:\n", 0, 1);
    printf("Old real size: %d\n", list.real_size);
    printf("Popped element: %d\n", pop(&list, 0)); // Removing element from List at index
    printf("Popped element: %d\n", pop(&list, 1)); // Removing element from List at index

    printf("New real size: %d\n", list.real_size);

    printf("\nPopping memory management:\n");
    for (int i = 2; i < 10; i++)
    {
        pop(&list, i); // Adding new valued to List
        printf("Real size: %d | Total size: %d\n", list.real_size, list.total_size);
    }

    free(list.ptr);
}
