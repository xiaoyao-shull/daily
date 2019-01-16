#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// begin: binary-heap module
#ifndef __BINARY_HEAP_MODULE_INCLUDED__
#define __BINARY_HEAP_MODULE_INCLUDED__
#define key_t int
typedef int (*less_t)(key_t, key_t);
typedef void (*swap_t)(key_t, key_t);
struct heap_t {
  less_t less;
  swap_t swap;
  int capacity;
  int size;
  key_t * data;
};
typedef struct heap_t * heap_t;

heap_t heap_make(int capacity, less_t less, swap_t swap) {
  struct heap_t * ptr = malloc(sizeof(*ptr) + sizeof(key_t) * (capacity + 1));
  ptr->capacity = capacity;
  ptr->less = less;
  ptr->swap = swap;
  ptr->size = 0;
  ptr->data = (key_t *) (ptr + 1);
  memset(ptr->data, 0, sizeof(int) * (capacity + 1));
  return ptr;
}

void heap_swap(heap_t heap, int i, int j) {
  int temp;
  heap->swap(heap->data[i], heap->data[j]);
  temp = heap->data[i];
  heap->data[i] = heap->data[j];
  heap->data[j] = temp;
}

void heap_heapify_up(heap_t heap, int index) {
  int parent = index / 2;
  if (parent <= 0) {
    return;
  }
  if (heap->less(heap->data[index], heap->data[parent])) {
    heap_swap(heap, index, parent);
    heap_heapify_up(heap, parent);
  }
}

void heap_heapify_down(heap_t heap, int index) {
  int left = index * 2;
  int right = index * 2 + 1;
  int min = index;
  if (left <= heap->size && heap->less(heap->data[left], heap->data[min])) {
    min = left;
  }
  if (right <= heap->size && heap->less(heap->data[right], heap->data[min])) {
    min = right;
  }
  if (min != index) {
    heap_swap(heap, min, index);
    heap_heapify_down(heap, min);
  }
}

void heap_push(heap_t heap, key_t value) {
  heap->size++;
  heap->data[heap->size] = value;
  heap_heapify_up(heap, heap->size);
}

void heap_remove(heap_t heap, int index) {
  heap_swap(heap, index, heap->size);
  heap->size--;
  heap_heapify_down(heap, index);
}

int heap_size(heap_t heap) {
  return heap->size;
}

int heap_top(heap_t heap) {
  return heap->data[1];
}
#undef  key_t
#endif // __BINARY_HEAP_MODULE_INCLUDED__
// end: binary-heap module

#define MAX_SIZE 100000

int array[MAX_SIZE];
int address[MAX_SIZE];

void swap(int i, int j) {
  int temp = address[i];
  address[i] = address[j];
  address[j] = temp;
}

int less(int i, int j) {
  return array[i] > array[j];
}

int main(int argc, char * argv[]) {
  int i;
  int size;
  int width;
  heap_t heap = heap_make(MAX_SIZE, less, swap);
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d", &array[i]);
  }
  scanf("%d", &width);
  for (i = 0; i < width; ++i) {
    address[i] = heap_size(heap) + 1;
    heap_push(heap, i);
  }
  printf("%d", array[heap_top(heap)]);
  while (i < size) {
    heap_remove(heap, address[i - width]);
    address[i] = heap_size(heap) + 1;
    heap_push(heap, i);
    printf(" %d", array[heap_top(heap)]);
    i++;
  }
  printf("\n");
  return 0;
}
