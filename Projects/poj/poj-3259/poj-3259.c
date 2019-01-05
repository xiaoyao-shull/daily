#include <stdio.h>
#include <stdlib.h>

// begin: deque_module
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
  if (deque->tail >= (deque->capacity + 1)) {
    deque->tail = 0;
  }
}

int deque_pop_front(deque_t deque) {
  int value = deque->data[deque->head];
  deque->head++;
  if (deque->head >= (deque->capacity + 1)) {
    deque->head = 0;
  }
  return value;
}

int deque_size(deque_t deque) {
  if (deque->tail >= deque->head) {
    return deque->tail - deque->head;

  } else {
    return deque->tail - deque->head + (deque->capacity + 1);
  }
}

int deque_empty(deque_t deque) {
  return deque_size(deque) == 0;
}
// end: deque_module

#define MAX_NODE_COUNT 500
#define MAX_EDGE_COUNT 2500
#define MAX_HOLE_COUNT 200

void run() {

  int edge_head[MAX_EDGE_COUNT * 2 + MAX_HOLE_COUNT + 1] = { 0 };
  int edge_cost[MAX_EDGE_COUNT * 2 + MAX_HOLE_COUNT + 1] = { 0 };
  int edge_next[MAX_EDGE_COUNT * 2 + MAX_HOLE_COUNT + 1] = { 0 };
  int node_edge[MAX_NODE_COUNT + 1] = { 0 };

  int node_dist[MAX_NODE_COUNT + 1] = { 0 };
  int node_dist_finite[MAX_NODE_COUNT + 1] = { 0 };
  int node_in_deque[MAX_NODE_COUNT + 1] = { 0 };
  int node_examined[MAX_NODE_COUNT + 1] = { 0 };

  int edge_count;
  int node_count;
  int hole_count;
  int i, j, k;
  int u, v, w;
  deque_t deque;

  scanf("%d%d%d", &node_count, &edge_count, &hole_count);
  deque = deque_make(node_count);
  for (i = 1, j = 0; i <= edge_count; ++i) {
    scanf("%d%d%d", &u, &v, &w);

    j++;
    edge_head[j] = v;
    edge_cost[j] = w;
    edge_next[j] = node_edge[u];
    node_edge[u] = j;

    j++;
    edge_head[j] = u;
    edge_cost[j] = w;
    edge_next[j] = node_edge[v];
    node_edge[v] = j;
  }
  for (i = 1; i <= hole_count; ++i) {
    scanf("%d%d%d", &u, &v, &w);

    j++;
    edge_head[j] = v;
    edge_cost[j] = -w;
    edge_next[j] = node_edge[u];
    node_edge[u] = j;
  }

  node_dist[1] = 0;
  node_dist_finite[1] = 1;
  deque_push_back(deque, 1);
  node_in_deque[1] = 1;

  while (!deque_empty(deque)) {
    u = deque_pop_front(deque);
    node_in_deque[u] = 0;
    node_examined[u]++;
    if (node_examined[u] >= node_count) {
      printf("YES\n");
      deque_free(&deque);
      return;
    }
    for (i = node_edge[u]; i != 0; i = edge_next[i]) {
      v = edge_head[i];
      w = edge_cost[i];
      if (!node_dist_finite[v]) {
        node_dist[v] = node_dist[u] + w;
        node_dist_finite[v] = 1;
        deque_push_back(deque, v);
        node_in_deque[v] = 1;

      } else if (node_dist[v] > node_dist[u] + w) {
        node_dist[v] = node_dist[u] + w;
        if (!node_in_deque[v]) {
          deque_push_back(deque, v);
          node_in_deque[v] = 1;
        }
      }
    }
  }
  printf("NO\n");
  deque_free(&deque);
  return;
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
