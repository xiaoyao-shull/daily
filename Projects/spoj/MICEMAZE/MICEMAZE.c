#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 100
#define MAX_EDGE_COUNT ((MAX_NODE_COUNT) * (MAX_NODE_COUNT - 1))

struct heap_t {
  int size;
  int * keys;
  int * key_value;
  int * key_index;
};
typedef struct heap_t * heap_t;

heap_t heap_make(int capacity) {
  struct heap_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (capacity + 1) * 3);
  ptr->size = 0;
  ptr->keys = (int *) (ptr + 1);
  ptr->key_value = (int *) (ptr + 1 + (capacity + 1));
  ptr->key_index = (int *) (ptr + 1 + (capacity + 1) * 2);
  memset(ptr->key_index, 0, sizeof(int) * (capacity + 1));
  memset(ptr->key_value, -1, sizeof(int) * (capacity + 1));
  return ptr;
}

void heap_swap(heap_t heap, int index1, int index2) {
  int temp;
  int key1 = heap->keys[index1];
  int key2 = heap->keys[index2];

  temp = heap->key_index[key1];
  heap->key_index[key1] = heap->key_index[key2];
  heap->key_index[key2] = temp;

  temp = heap->keys[index1];
  heap->keys[index1] = heap->keys[index2];
  heap->keys[index2] = temp;
}

void heap_heapify_up(heap_t heap, int index) {
  int parent = index / 2;
  if (parent <= 0) {
    return;
  }
  if (heap->key_value[heap->keys[parent]] > heap->key_value[heap->keys[index]]) {
    heap_swap(heap, index, parent);
    heap_heapify_up(heap, parent);
  }
}

void heap_heapify_down(heap_t heap, int index) {
  int left = index * 2;
  int right = index * 2 + 1;
  int min = index;
  if (left <= heap->size && heap->key_value[heap->keys[left]] < heap->key_value[heap->keys[min]]) {
    min = left;
  }
  if (right <= heap->size && heap->key_value[heap->keys[right]] < heap->key_value[heap->keys[min]]) {
    min = right;
  }
  if (min != index) {
    heap_swap(heap, min, index);
    heap_heapify_down(heap, min);
  }
}

void heap_push(heap_t heap, int key, int value) {
  heap->size++;
  heap->key_value[key] = value;
  heap->key_index[key] = heap->size;
  heap->keys[heap->size] = key;
  heap_heapify_up(heap, heap->size);
}

int heap_pop(heap_t heap) {
  int key = heap->keys[1];
  heap_swap(heap, 1, heap->size);
  heap->size--;
  heap_heapify_down(heap, 1);
  return key;
}

void heap_decrease_key(heap_t heap, int key, int value) {
  if (heap->key_value[key] <= value) {
    return;
  }
  heap->key_value[key] = value;
  heap_heapify_up(heap, heap->key_index[key]);
}

int heap_size(heap_t heap) {
  return heap->size;
}

int heap_value(heap_t heap, int key) {
  return heap->key_value[key];
}

int main(int argc, char * argv[]) {
  int matrix[(MAX_NODE_COUNT + 1) * (MAX_NODE_COUNT + 1)];
  int node_edge[MAX_NODE_COUNT + 1];
  int edge_head[MAX_EDGE_COUNT + 1];
  int edge_cost[MAX_EDGE_COUNT + 1];
  int edge_next[MAX_EDGE_COUNT + 1];
  int node_count;
  int edge_count;
  int source;
  int time;
  int i, j;
  int u, v, w;
  int du, dv;
  heap_t heap = heap_make(MAX_NODE_COUNT);
  memset(matrix, -1, sizeof(matrix));
  memset(edge_next, 0, sizeof(edge_next));
  memset(node_edge, 0, sizeof(node_edge));
  scanf("%d%d%d%d", &node_count, &source, &time, &edge_count);
  while (edge_count--) {
    scanf("%d%d%d", &v, &u, &w);
    if (matrix[u * node_count + v] == -1 || matrix[u * node_count + v] > w) {
      matrix[u * node_count + v] = w;
    }
  }
  for (u = 1, edge_count = 0; u <= node_count; ++u) {
    for (v = 1; v <= node_count; ++v) {
      if (u == v || matrix[u * node_count + v] == -1) {
        continue;
      }
      edge_count++;
      edge_cost[edge_count] = matrix[u * node_count + v];
      edge_head[edge_count] = v;
      edge_next[edge_count] = node_edge[u];
      node_edge[u] = edge_count;
    }
  }
  heap_push(heap, source, 0);
  while (heap_size(heap) > 0) {
    u = heap_pop(heap);
    du = heap_value(heap, u);
    for (i = node_edge[u]; i != 0; i = edge_next[i]) {
      v = edge_head[i];
      w = edge_cost[i];
      dv = heap_value(heap, v);
      if (dv == -1) {
        heap_push(heap, v, du + w);

      } else if (dv > du + w) {
        heap_decrease_key(heap, v, du + w);
      }
    }
  }
  for (u = 1, i = 0; u <= node_count; ++u) {
    w = heap_value(heap, u);
    if (w != -1 && w <= time) {
      i++;
    }
  }
  printf("%d\n", i);
  return 0;
}
