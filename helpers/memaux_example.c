
#include <stdio.h>
#include "memaux_2.h"

void print_list(IntList *list)
{
    for (int i = 0; i < (*list).real_size; i++)
    {
        printf("%d\n", (*list).ptr[i]);
    }
}
int main()
{
    // Declaring new List
    IntList list = {
        .ptr = NULL,
        .real_size = 0,
        .total_size = 0};

    printf("Appending to the list:\n");

    for (int i = 0; i < 10; i++)
    {
        append(&list, i); // Adding new value to List
        printf("Real size: %d | Total size: %d\n", list.real_size, list.total_size);
    }

    // Printing the List

    printf("List after appending:\n");
    print_list(&list);

    printf("\\Removing elements at index %d and %d:\n", 0, 1);
    printf("Old real size: %d\n", list.real_size);
    printf("Removed element: %d\n", remove_index(&list, 0)); // Removing element from List at index
    printf("Removed element: %d\n", remove_index(&list, 1)); // Removing element from List at index
    printf("Popping an element (removing last element)\n");
    pop(&list);

    printf("New real size: %d\nList after removal&pop", list.real_size);
    print_list(&list);
    printf("\nRemoval memory management:\n");

    int list_size = list.real_size;
    for (int i = 0; i < list_size; i++)
    {
        remove_index(&list, i); // Removing value from List
        printf("Real size: %d | Total size: %d\n", list.real_size, list.total_size);
    }

    free(list.ptr);
}
