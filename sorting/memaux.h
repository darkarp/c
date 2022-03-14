#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
############################
Structures
############################
*/

// This item can represent anything in the value field
typedef struct Item {
  void *value;
} Item;

// This structure will hold an Item List
// It keeps track of real size (actual elements)
// and total size (total allocated memory)
typedef struct List {
  Item *ptr;
  size_t total_size;
  size_t real_size;
} List;

/*
############################
Helper Auxiliary functions
############################
*/

// Find minimum between two numbers
int find_min(int x, int y) { return (x < y) ? x : y; }

// Swap two values
void swap(void *item_1, void *item_2, size_t size) {
  void *temp = malloc(size);
  memcpy(temp, item_1, size);
  memcpy(item_1, item_2, size);
  memcpy(item_2, temp, size);
  free(temp);
}

// Print arrays
void print_array_int(Item *item_list, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", *(int *)(item_list[i]).value);
  printf("\n");
}

void print_array_char(Item *item_list, int size) {
  for (int i = 0; i < size; i++)
    printf("%c ", *(char *)(item_list[i]).value);
  printf("\n");
}

/*
############################
List Functions - Creation
############################
*/

// Append to List
// Check if memory allocated is enough to hold the new value.
// If not, multiply allocated memory by 2
int append(List *list, Item value) {

  size_t t_size = list->total_size, r_size = list->real_size;
  size_t new_r_size = r_size + 1, new_t_size = (new_r_size + t_size) * 2;

  if (t_size <= new_r_size) // checking to see if we already have big enough
                            // size to add new element
  {

    void *new_ptr =
        realloc(list->ptr,
                new_t_size * sizeof(Item)); // leveraging the fact that realloc
                                            // with a NULL ptr is just a malloc
    if (new_ptr) {
      list->ptr = (Item *)new_ptr;   // update ptr after realloc
      list->total_size = new_t_size; // updating total size
    } else {
      return 1;
    }
  }
  list->ptr[r_size] = value;    // adding the element to the List
  list->real_size = new_r_size; // realsize increments by 1
  return 0;
}

// Removes item at index from List
// If memory allocated is over 2x the memory needed
// reduce the allocated memory.
int remove_index(List *list, int index) {
  size_t r_size = list->real_size;
  if (r_size > 0) {
    list->real_size -= 1;

    // Shifting the values so we don't have holes
    for (int i = index; i < r_size - 1; i++)
      list->ptr[i] = list->ptr[i + 1];

    // Making the List shorter if it falls bellow threshold. This can be removed
    // if inneficient in certain applications
    if (list->real_size * 2 < list->total_size) {
      void *new_ptr =
          realloc(list->ptr,
                  r_size * sizeof(Item)); // leveraging the fact that realloc
                                          // with a NULL ptr is just a malloc
      if (new_ptr) {
        list->ptr = (Item *)new_ptr; // update ptr after realloc
        list->total_size = r_size;   // updating total size
      }
    }
    return 0;
  }
  return -1; // Can't pop if it's empty
}

// Removes last element if it exists
int pop(List *list) {
  if (list->real_size > 0)
    return --list->real_size;
  return -1; // Can't pop if it's empty
}

// Appends to list without bound checking
// Useful when you are sure there will be no UB
void push(List *list, Item value) {
  list->ptr[list->real_size++] = value; // adding the element to the List
}
