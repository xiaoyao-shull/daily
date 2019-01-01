#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (* heap_less_t)(int, int);
typedef void (* heap_swap_t)(int, int);
typedef struct heap_t {
  heap_less_t less;
  heap_swap_t swap;
  int capacity;
  int size;
  int * data;

} * heap_t;

heap_t heap_make(heap_less_t less, heap_swap_t swap, int capacity) {
  struct heap_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (capacity + 1));
  ptr->less = less;
  ptr->swap = swap;
  ptr->capacity = capacity;
  ptr->size = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}

void heap_clean(heap_t heap) {
  heap->size = 0;
}

void heap_shift_up(heap_t heap, int index) {
  int parent = index / 2;
  int temp;
  if (parent <= 0 || heap->less(heap->data[parent], heap->data[index])) {
    return;
  }
  heap->swap(index, parent);
  temp = heap->data[index];
  heap->data[index] = heap->data[parent];
  heap->data[parent] = temp;
  heap_shift_up(heap, parent);
}

void heap_shift_down(heap_t heap, int index) {
  int temp;
  int min = index;
  int left = index * 2;
  int right = index * 2 + 1;
  if (left <= heap->size && heap->less(heap->data[left], heap->data[min])) {
    min = left;
  }
  if (right <= heap->size && heap->less(heap->data[right], heap->data[min])) {
    min = right;
  }
  if (min == index) {
    return;
  }
  heap->swap(min, index);
  temp = heap->data[min];
  heap->data[min] = heap->data[index];
  heap->data[index] = temp;
  heap_shift_down(heap, min);
}

int heap_insert(heap_t heap, int value) {
  heap->size++;
  heap->data[heap->size] = value;
  heap_shift_up(heap, heap->size);
  return heap->size;
}

void heap_delete_min(heap_t heap) {
  heap->data[1] = heap->data[heap->size];
  heap->size--;
  heap_shift_down(heap, 1);
}

int heap_find_min(heap_t heap) {
  return heap->data[1];
}

int heap_size(heap_t heap) {
  return heap->size;
}

#define MAX_NODE_COUNT 1000000
#define MAX_EDGE_COUNT 1000000

int node_less_f(int u, int v);
int node_less_b(int u, int v);
void node_swap_f(int u, int v);
void node_swap_b(int u, int v);

int node_count;
int edge_count;
int edge_head[MAX_EDGE_COUNT + 1];
int edge_tail[MAX_EDGE_COUNT + 1];
int edge_cost[MAX_EDGE_COUNT + 1];

int edge_next_f[MAX_EDGE_COUNT + 1];
int node_edge_f[MAX_NODE_COUNT + 1];
int node_dist_f[MAX_NODE_COUNT + 1];
int node_heap_f[MAX_NODE_COUNT + 1];
int node_mark_f[MAX_NODE_COUNT + 1];
heap_t heap_f;

int edge_next_b[MAX_EDGE_COUNT + 1];
int node_edge_b[MAX_NODE_COUNT + 1];
int node_dist_b[MAX_NODE_COUNT + 1];
int node_heap_b[MAX_NODE_COUNT + 1];
int node_mark_b[MAX_NODE_COUNT + 1];
heap_t heap_b;

void run() {
  int i, j;
  int u, v, w;
  long long result;

  memset(edge_next_f, 0, sizeof(edge_next_f));
  memset(node_edge_f, 0, sizeof(node_edge_f));
  memset(node_mark_f, 0, sizeof(node_mark_f));
  memset(node_dist_f, -1, sizeof(node_dist_f));
  heap_clean(heap_f);

  memset(edge_next_b, 0, sizeof(edge_next_b));
  memset(node_edge_b, 0, sizeof(node_edge_b));
  memset(node_mark_b, 0, sizeof(node_mark_b));
  memset(node_dist_b, -1, sizeof(node_dist_b));
  heap_clean(heap_b);

  scanf("%d%d", &node_count, &edge_count);
  for (i = 1; i <= edge_count; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    edge_tail[i] = u;
    edge_head[i] = v;
    edge_cost[i] = w;
    edge_next_f[i] = node_edge_f[u];
    node_edge_f[u] = i;
    edge_next_b[i] = node_edge_b[v];
    node_edge_b[v] = i;
  }
  node_dist_f[1] = 0;
  node_heap_f[1] = heap_insert(heap_f, 1);
  node_dist_b[1] = 0;
  node_heap_b[1] = heap_insert(heap_b, 1);
  while (heap_size(heap_f) > 0) {
    u = heap_find_min(heap_f);
    heap_delete_min(heap_f);
    node_mark_f[u] = 1;
    for (i = node_edge_f[u]; i != 0; i = edge_next_f[i]) {
      v = edge_head[i];
      w = edge_cost[i];
      if (node_dist_f[v] == -1) {
        node_dist_f[v] = node_dist_f[u] + w;
        node_heap_f[v] = heap_insert(heap_f, v);

      } else if (node_dist_f[v] > node_dist_f[u] + w) {
        node_dist_f[v] = node_dist_f[u] + w;
        heap_shift_up(heap_f, node_heap_f[v]);
      }
    }

    u = heap_find_min(heap_b);
    heap_delete_min(heap_b);
    node_mark_b[u] = 1;
    for (i = node_edge_b[u]; i != 0; i = edge_next_b[i]) {
      v = edge_tail[i];
      w = edge_cost[i];
      if (node_dist_b[v] == -1) {
        node_dist_b[v] = node_dist_b[u] + w;
        node_heap_b[v] = heap_insert(heap_b, v);

      } else if (node_dist_b[v] > node_dist_b[u] + w) {
        node_dist_b[v] = node_dist_b[u] + w;
        heap_shift_up(heap_b, node_heap_b[v]);
      }
    }
  }
  for (i = 1, result = 0; i <= node_count; ++i) {
    result += node_dist_f[i];
    result += node_dist_b[i];
  }
  printf("%lld\n", result);
}

int main(int argc, char * argv[]) {
  int case_count;
  heap_f = heap_make(node_less_f, node_swap_f, MAX_NODE_COUNT);
  heap_b = heap_make(node_less_b, node_swap_b, MAX_NODE_COUNT);
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}

int node_less_f(int u, int v) {
  if (node_dist_f[v] == -1) {
    return 1;
  }
  if (node_dist_f[u] == -1) {
    return 0;
  }
  return node_dist_f[u] < node_dist_f[v];
}

int node_less_b(int u, int v) {
  if (node_dist_b[v] == -1) {
    return 1;
  }
  if (node_dist_b[u] == -1) {
    return 0;
  }
  return node_dist_b[u] < node_dist_b[v];
}

void node_swap_f(int u, int v) {
  int temp = node_heap_f[u];
  node_heap_f[u] = node_heap_f[v];
  node_heap_f[v] = temp;
}

void node_swap_b(int u, int v) {
  int temp = node_heap_b[u];
  node_heap_b[u] = node_heap_b[v];
  node_heap_b[v] = temp;
}
