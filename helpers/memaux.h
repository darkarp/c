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

    if (t_size <= new_r_size)
    {
        void *new_ptr = realloc(list->ptr, new_t_size * sizeof(int));
        if (new_ptr)
        {
            list->ptr = (int *)new_ptr;
            list->total_size = new_t_size;
        }
        else
        {
            return 1;
        }
    }

    list->ptr[r_size] = value;
    list->real_size = new_r_size;
    return 0;
}

int pop(List *list, int index)
{
    size_t r_size = list->real_size;
    int elem = list->ptr[index];
    if (r_size > 0)
    {
        list->real_size -= 1;
        for (int i = index; i < r_size - 1; i++)
            list->ptr[i] = list->ptr[i + 1];
        return elem;
    }
    return -1;
}
