#include "memaux.h"

void quicksort(Item *collection, const int left, const int right,
               bool compare(Item i1, Item i2, bool), bool reversed) {
  int i, j, pivot;
  if (left < right) {
    // Pivot is the middle element for now
    // Like this we observe best case scenario with a sorted list
    pivot = (left + right) / 2;
    i = left;
    j = right;

    // Keep checking from both ends if values are smaller
    // or bigger than pivot and swap accordingly.
    // Stop when i and j meet.
    while (i < j) {
      for (; !compare(collection[i], collection[pivot], reversed) && i < right;
           i++)
        ;
      for (; compare(collection[j], collection[pivot], reversed); j--)
        ;
      if (i < j)
        swap(&collection[i], &collection[j], sizeof(Item));
    }
    // Swap pivot back
    swap(&collection[pivot], &collection[j], sizeof(Item));

    // Recursively run for both elements before pivot and after
    quicksort(collection, left, j - 1, compare, reversed);
    quicksort(collection, j + 1, right, compare, reversed);
  }
}

void bubble_sort(Item *collection, int size,
                 bool compare(Item i1, Item i2, bool), bool reversed) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (compare(collection[j], collection[j + 1], reversed)) {
        swap(&collection[j], &collection[j + 1], sizeof(Item));
      }
    }
  }
}