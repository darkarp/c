#include "sorting.h"
#include <stdio.h>

#define QUICK

bool compare_ints(Item i1, Item i2, bool reversed) {
  bool condition = *(int *)(i1).value > *(int *)(i2).value;
  return reversed ? !condition : condition;
}
bool compare_chars(Item i1, Item i2, bool reversed) {
  bool condition = *(char *)(i1).value > *(char *)(i2).value;
  return reversed ? !condition : condition;
}

int main() {
  // Declaring the arrays to sort
  int ints[10] = {5, 3, 7, 2, 8, 9, 1, 2, 23, 76};
  char chars[10] = {'B', 'C', 'A', 'P', 'Q', 'H', 'S', 'P', 'X', 'D'};

  // Custom type List to abstract away the real types
  List int_list_obj = {NULL, 0, 0};
  List char_list_obj = {NULL, 0, 0};

  // Populating the List
  // Each value added to the List is an Item
  for (int i = 0; i < 10; i++) {
    Item int_item = {&ints[i]};
    Item char_item = {&chars[i]};
    append(&int_list_obj, int_item);
    append(&char_list_obj, char_item);
  }

  // Before sorting
  printf("Before:\n");
  printf("Ints: ");
  print_array_int(int_list_obj.ptr, int_list_obj.real_size);
  printf("Chars: ");
  print_array_char(char_list_obj.ptr, char_list_obj.real_size);

// Perform quick_sort or bubble_sort
#ifdef QUICKSORT
  quicksort(int_list_obj.ptr, 0, int_list_obj.real_size - 1, compare_ints,
            false);
  quicksort(char_list_obj.ptr, 0, char_list_obj.real_size - 1, compare_chars,
            false);
#else
  bubble_sort(int_list_obj.ptr, int_list_obj.real_size, compare_ints, false);
  bubble_sort(char_list_obj.ptr, char_list_obj.real_size, compare_chars, false);
#endif

  // After sorting
  printf("\nAfter:\n");
  printf("Ints: ");
  print_array_int(int_list_obj.ptr, int_list_obj.real_size);
  printf("Chars: ");
  print_array_char(char_list_obj.ptr, char_list_obj.real_size);

  return 0;
}