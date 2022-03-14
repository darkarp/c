#include "memaux.h"

// Quicksort
void quick_sort(Item *collection, int start, int end,
                bool compare(Item i1, Item i2, bool), bool reversed) {
  if (end > start + 1) {
    Item pivot = collection[start];
    int left = start + 1, right = end;
    while (left < right) {
      if (compare(pivot, collection[left], reversed))
        left++;
      else
        swap(&collection[left], &collection[--right], sizeof(Item));
    }
    swap(&collection[--left], &collection[start], sizeof(Item));
    quick_sort(collection, start, left, compare, reversed);
    quick_sort(collection, right, end, compare, reversed);
  }
}

// Bubblesort
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