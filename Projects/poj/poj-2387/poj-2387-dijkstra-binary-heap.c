#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BINARY_HEAP_INCLUDED__
#define BINARY_HEAP_INCLUDED__
#define T int
typedef int (*binary_heap_less_t)(T, T);
typedef void (*binary_heap_swap_t)(T, int);
typedef void (*binary_heap_push_t)(T, int);

typedef struct binary_heap_t {
  binary_heap_less_t less;
  binary_heap_swap_t swap;
  binary_heap_push_t push;
  int capacity;
  int size;
  T * data;

} * binary_heap_t;

binary_heap_t binary_heap_new(int capacity, binary_heap_less_t less, binary_heap_swap_t swap, binary_heap_push_t push) {
  struct binary_heap_t * ptr = malloc(sizeof(*ptr) + sizeof(T) * (capacity + 1));
  ptr->less = less;
  ptr->swap = swap;
  ptr->push = push;
  ptr->capacity = capacity;
  ptr->size = 0;
  ptr->data = (T *) (ptr + 1);
  memset(ptr->data, 0, sizeof(T) * (capacity + 1));
  return ptr;
}

void binary_heap_del(binary_heap_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void binary_heap_shift_down(binary_heap_t binary_heap, int index) {
  T tmp;
  int min = index;
  int left = index * 2;
  int right = index * 2 + 1;

  if (left <= binary_heap->size && binary_heap->less(binary_heap->data[left], binary_heap->data[min])) {
    min = left;
  }
  if (right <= binary_heap->size && binary_heap->less(binary_heap->data[right], binary_heap->data[min])) {
    min = right;
  }
  if (min != index) {
    binary_heap->swap(binary_heap->data[min], binary_heap->data[index]);
    tmp = binary_heap->data[min];
    binary_heap->data[min] = binary_heap->data[index];
    binary_heap->data[index] = tmp;
    binary_heap_shift_down(binary_heap, min);
  }
}

void binary_heap_shift_up(binary_heap_t binary_heap, int index) {
  T tmp;
  int parent = index / 2;
  if (parent <= 0) {
    return;
  }
  if (binary_heap->less(binary_heap->data[index], binary_heap->data[parent])) {
    binary_heap->swap(binary_heap->data[index], binary_heap->data[parent]);
    tmp = binary_heap->data[index];
    binary_heap->data[index] = binary_heap->data[parent];
    binary_heap->data[parent] = tmp;
    binary_heap_shift_up(binary_heap, parent);
  }
}

void binary_heap_push(binary_heap_t binary_heap, T value) {
  binary_heap->size++;
  binary_heap->data[binary_heap->size] = value;
  binary_heap->push(value, binary_heap->size);
  binary_heap_shift_up(binary_heap, binary_heap->size);
}

T binary_heap_pop(binary_heap_t binary_heap) {
  T value = binary_heap->data[1];
  binary_heap->data[1] = binary_heap->data[binary_heap->size];
  binary_heap->size--;
  binary_heap_shift_down(binary_heap, 1);
  return value;
}
#endif // BINARY_HEAP_INCLUDED__

#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 4000

int edge_head[MAX_EDGE_COUNT * 2 + 1];
int edge_next[MAX_EDGE_COUNT * 2 + 1];
int edge_cost[MAX_EDGE_COUNT * 2 + 1];

int node_heap[MAX_NODE_COUNT + 1];
int node_edge[MAX_NODE_COUNT + 1];
int node_dist[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];

int less(int i, int j) {
  if (node_dist[j] == -1) {
    return 1;
  }
  if (node_dist[i] == -1) {
    return 0;
  }
  return node_dist[i] < node_dist[j];
}

void push(int value, int index) {
  node_heap[value] = index;
}

void swap(int i, int j) {
  int tmp = node_heap[i];
  node_heap[i] = node_heap[j];
  node_heap[j] = tmp;
}

int main(int argc, char * argv[]) {
  int edge_count;
  int node_count;
  int i, j, k;
  int u, v, w;
  binary_heap_t binary_heap;

  // 1. Construct Graph.
  scanf("%d%d", &edge_count, &node_count);
  memset(node_edge, 0, sizeof(node_edge));
  for (i = 0, j = 1; i < edge_count; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    edge_head[j] = v;
    edge_cost[j] = w;
    edge_next[j] = node_edge[u];
    node_edge[u] = j;
    j++;

    edge_head[j] = u;
    edge_cost[j] = w;
    edge_next[j] = node_edge[v];
    node_edge[v] = j;
    j++;
  }

  // 2. Dijkstra.
  memset(node_mark, 0, sizeof(node_mark));
  for (i = 1; i <= node_count; ++i) {
    node_dist[i] = i == 1 ? 0 : -1;
  }
  binary_heap = binary_heap_new(node_count, less, swap, push);
  binary_heap_push(binary_heap, 1);

  while (1) {
    j = binary_heap_pop(binary_heap);
    node_mark[j] = 1;
    for (i = node_edge[j]; i != 0; i = edge_next[i]) {
      k = edge_head[i];
      if (node_dist[k] == -1) {
        node_dist[k] = node_dist[j] + edge_cost[i];
        binary_heap_push(binary_heap, k);

      } else if (node_dist[k] > node_dist[j] + edge_cost[i]) {
        node_dist[k] = node_dist[j] + edge_cost[i];
        binary_heap_shift_up(binary_heap, node_heap[k]);
      }
    }
    if (j == node_count) {
      break;
    }
  }

  printf("%d\n", node_dist[node_count]);
  return 0;
}
