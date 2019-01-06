#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// begin: deque module
typedef struct deque_t {
  int capacity;
  int head;
  int tail;
  int * data;

} * deque_t;

deque_t deque_make(int capacity) {
  struct deque_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (capacity + 1));
  ptr->capacity = capacity;
  ptr->head = 0;
  ptr->tail = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}

void deque_free(deque_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void deque_push_back(deque_t deque, int value) {
  deque->data[deque->tail] = value;
  deque->tail++;
  if (deque->tail == (deque->capacity + 1)) {
    deque->tail = 0;
  }
}

int deque_get(deque_t deque, int index) {
  index += deque->head;
  if (index >= (deque->capacity + 1)) {
    index -= (deque->capacity + 1);
  }
  return deque->data[index];
}

void deque_set(deque_t deque, int index, int value) {
  index += deque->head;
  if (index >= (deque->capacity + 1)) {
    index -= (deque->capacity + 1);
  }
  deque->data[index] = value;
}

int deque_size(deque_t deque) {
  if (deque->tail >= deque->head) {
    return deque->tail - deque->head;

  } else {
    return deque->tail - deque->head + (deque->capacity + 1);
  }
}

void deque_sort_desc(deque_t deque) {
  int size = deque_size(deque);
  int i;
  int new_size;
  int temp;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (deque_get(deque, i - 1) < deque_get(deque, i)) {
        temp = deque_get(deque, i - 1);
        deque_set(deque, i - 1, deque_get(deque, i));
        deque_set(deque, i, temp);
        new_size = i;
      }
    }
    size = new_size;
  }
}
// end: deque module

#define MAX_NODE_COUNT 10000
#define MAX_EDGE_COUNT 9999

int edge_head[MAX_EDGE_COUNT * 2 + 1];
int edge_next[MAX_EDGE_COUNT * 2 + 1];
int node_edge[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];

int dfs(int node) {
  int max_depth = 0;
  int new_depth;
  int i, j;
  node_mark[node] = 1;
  for (i = node_edge[node]; i != 0; i = edge_next[i]) {
    j = edge_head[i];
    if (node_mark[j]) {
      continue;
    }
    new_depth = 1 + dfs(j);
    if (max_depth < new_depth) {
      max_depth = new_depth;
    }
  }
  node_mark[node] = 0;
  return max_depth;
}

int main(int argc, char * argv[]) {
  int node_count;
  int edge_count;
  int u, v;
  deque_t deque;
  int i, j;

  scanf("%d", &node_count);
  memset(node_edge, 0, sizeof(node_edge));
  memset(edge_next, 0, sizeof(edge_next));
  memset(node_mark, 0, sizeof(node_mark));
  edge_count = 0;
  while (scanf("%d%d", &u, &v) > 0) {
    edge_count++;
    edge_head[edge_count] = v;
    edge_next[edge_count] = node_edge[u];
    node_edge[u] = edge_count;

    edge_count++;
    edge_head[edge_count] = u;
    edge_next[edge_count] = node_edge[v];
    node_edge[v] = edge_count;
  }

  deque = deque_make(node_count - 1);
  node_mark[1] = 1;
  for (i = node_edge[1]; i != 0; i = edge_next[i]) {
    deque_push_back(deque, dfs(edge_head[i]));
  }
  deque_sort_desc(deque);
  if (deque_size(deque) == 1) {
    printf("%d\n", 1 + deque_get(deque, 0));

  } else {
    printf("%d\n", 2 + deque_get(deque, 0) + deque_get(deque, 1));
  }
  return 0;
}
