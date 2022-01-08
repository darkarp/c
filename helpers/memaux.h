#include <stdlib.h>

typedef struct List
{
    int *ptr;
    size_t total_size;
    size_t real_size;
} List;

int append(List *list, int value)
{
    size_t t_size = list->total_size, r_size = list->real_size;
    size_t new_r_size = r_size + 1, new_t_size = (new_r_size + t_size) * 2;

    if (t_size <= new_r_size) // checking to see if we already have big enough size to add new element
    {
        void *new_ptr = realloc(list->ptr, new_t_size * sizeof(int)); // leveraging the fact that realloc with a NULL ptr is just a malloc
        if (new_ptr)
        {
            list->ptr = (int *)new_ptr;    // update ptr after realloc
            list->total_size = new_t_size; // updating total size
        }
        else
        {
            return 1;
        }
    }

    list->ptr[r_size] = value;    // adding the element to the List
    list->real_size = new_r_size; // realsize increments by 1
    return 0;
}

int pop(List *list, int index)
{
    size_t r_size = list->real_size;
    int elem = list->ptr[index];
    if (r_size > 0)
    {
        list->real_size -= 1;

        // Shifting the values so we don't have holes
        for (int i = index; i < r_size - 1; i++)
            list->ptr[i] = list->ptr[i + 1];

        // Making the List shorter if it falls bellow threshold. This can be removed if inneficient in certain applications
        if (list->real_size * 2 < list->total_size)
        {
            void *new_ptr = realloc(list->ptr, r_size * sizeof(int)); // leveraging the fact that realloc with a NULL ptr is just a malloc
            if (new_ptr)
            {
                list->ptr = (int *)new_ptr; // update ptr after realloc
                list->total_size = r_size;  // updating total size
            }
        }
        return elem;
    }
    return -1; // Can't pop if it's empty
}
