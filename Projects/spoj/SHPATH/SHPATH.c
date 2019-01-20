#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct heap_t {
  int capacity;
  int size;
  int * value;
  int * index;
  int * array;
};

typedef struct heap_t * heap_t;

heap_t heap_make(int capacity) {
  struct heap_t * ptr = malloc(sizeof(*ptr));
  ptr->capacity = capacity;
  ptr->size = 0;
  ptr->value = malloc(sizeof(int) * (capacity + 1));
  ptr->index = malloc(sizeof(int) * (capacity + 1));
  ptr->array = malloc(sizeof(int) * (capacity + 1));
  return ptr;
}

void heap_free(heap_t * ptr) {
  free((*ptr)->index);
  free((*ptr)->value);
  free((*ptr)->array);
  free(*ptr);
  *ptr = NULL;
}

void heap_swap(heap_t heap, int i, int j) {
  int temp;

  temp = heap->index[heap->array[i]];
  heap->index[heap->array[i]] = heap->index[heap->array[j]];
  heap->index[heap->array[j]] = temp;

  temp = heap->array[i];
  heap->array[i] = heap->array[j];
  heap->array[j] = temp;
}

void heap_heapify_up(heap_t heap, int index) {
  int parent = index / 2;
  if (parent <= 0) {
    return;
  }
  if (heap->value[heap->array[parent]] > heap->value[heap->array[index]]) {
    heap_swap(heap, parent, index);
    heap_heapify_up(heap, parent);
  }
}

void heap_heapify_down(heap_t heap, int index) {
  int left = index * 2;
  int right = index * 2 + 1;
  int min = index;
  if (left <= heap->size && heap->value[heap->array[left]] < heap->value[heap->array[min]]) {
    min = left;
  }
  if (right <= heap->size && heap->value[heap->array[right]] < heap->value[heap->array[min]]) {
    min = right;
  }
  if (min != index) {
    heap_swap(heap, min, index);
    heap_heapify_down(heap, min);
  }
}

void heap_push(heap_t heap, int key, int value) {
  heap->size++;
  heap->index[key] = heap->size;
  heap->value[key] = value;
  heap->array[heap->size] = key;
  heap_heapify_up(heap, heap->size);
}

void heap_pop(heap_t heap) {
  heap_swap(heap, 1, heap->size);
  heap->size--;
  heap_heapify_down(heap, 1);
}

void heap_update(heap_t heap, int key, int value) {
  if (value < heap->value[key]) {
    heap->value[key] = value;
    heap_heapify_up(heap, heap->index[key]);
    return;
  }
  if (value > heap->value[key]) {
    heap->value[key] = value;
    heap_heapify_down(heap, heap->index[key]);
    return;
  }
}

int heap_top(heap_t heap) {
  return heap->array[1];
}

struct graph_t {
  int edge_capacity;
  int node_count;
  int edge_count;
  int * node_edge;
  int * edge_next;
  int * edge_head;
  int * edge_cost;
};

typedef struct graph_t * graph_t;

graph_t graph_make(int node_count) {
  int edge_capacity = node_count;
  struct graph_t * ptr = malloc(sizeof(*ptr));
  ptr->edge_capacity = edge_capacity;
  ptr->node_count = node_count;
  ptr->edge_count = 0;
  ptr->node_edge = malloc(sizeof(int) * (node_count + 1));
  ptr->edge_next = malloc(sizeof(int) * (edge_capacity + 1));
  ptr->edge_head = malloc(sizeof(int) * (edge_capacity + 1));
  ptr->edge_cost = malloc(sizeof(int) * (edge_capacity + 1));
  memset(ptr->node_edge, 0, sizeof(int) * (node_count + 1));
  memset(ptr->edge_next, 0, sizeof(int) * (edge_capacity + 1));
  return ptr;
}

void graph_free(graph_t * ptr) {
  free((*ptr)->node_edge);
  free((*ptr)->edge_next);
  free((*ptr)->edge_head);
  free((*ptr)->edge_cost);
  free(*ptr);
  *ptr = NULL;
}

void graph_add_edge(graph_t graph, int tail, int head, int cost) {
  graph->edge_count++;
  if (graph->edge_count > graph->edge_capacity) {
    graph->edge_head = realloc(graph->edge_head, sizeof(int) * (graph->edge_capacity * 2 + 1));
    memset(graph->edge_head + (graph->edge_capacity + 1), 0, graph->edge_capacity);

    graph->edge_next = realloc(graph->edge_next, sizeof(int) * (graph->edge_capacity * 2 + 1));
    memset(graph->edge_next + (graph->edge_capacity + 1), 0, graph->edge_capacity);

    graph->edge_cost = realloc(graph->edge_cost, sizeof(int) * (graph->edge_capacity * 2 + 1));
    memset(graph->edge_cost + (graph->edge_capacity + 1), 0, graph->edge_capacity);

    graph->edge_capacity += graph->edge_capacity;
  }
  graph->edge_head[graph->edge_count] = head;
  graph->edge_cost[graph->edge_count] = cost;
  graph->edge_next[graph->edge_count] = graph->node_edge[tail];
  graph->node_edge[tail] = graph->edge_count;
}

int graph_dijkstra(graph_t graph, int s, int t) {
  int * node_dist = malloc(sizeof(int) * (graph->node_count + 1));
  int * node_mark = malloc(sizeof(int) * (graph->node_count + 1));
  heap_t heap = heap_make(graph->node_count);
  int u, v, w;
  int i;
  memset(node_dist, -1, sizeof(int) * (graph->node_count + 1));
  memset(node_mark, 0, sizeof(int) * (graph->node_count + 1));
  node_dist[s] = 0;
  heap_push(heap, s, 0);
  while (node_mark[t] == 0) {
    u = heap_top(heap);
    heap_pop(heap);
    node_mark[u] = 1;
    for (i = graph->node_edge[u]; i != 0; i = graph->edge_next[i]) {
      v = graph->edge_head[i];
      w = graph->edge_cost[i];
      if (node_dist[v] == -1) {
        node_dist[v] = node_dist[u] + w;
        heap_push(heap, v, node_dist[u] + w);

      } else if (node_dist[v] > node_dist[u] + w) {
        node_dist[v] = node_dist[u] + w;
        heap_update(heap, v, node_dist[u] + w);
      }
    }
  }
  w = node_dist[t];
  free(node_dist);
  free(node_mark);
  heap_free(&heap);
  return w;
}

#define MAX_NODE_COUNT 10000

char cities[MAX_NODE_COUNT + 1][11];

void run() {
  int node_count;
  int edge_count;
  int path_count;
  int i, j;
  int u, v, w;
  graph_t graph;
  char s[11];
  char t[11];
  scanf("%d", &node_count);
  graph = graph_make(node_count);
  for (u = 1; u <= node_count; ++u) {
    scanf("%s", cities[u]);
    scanf("%d", &i);
    while (i--) {
      scanf("%d%d", &v, &w);
      graph_add_edge(graph, u, v, w);
    }
  }
  scanf("%d", &path_count);
  while (path_count--) {
    scanf("%s%s", s, t);
    for (i = 1; strcmp(cities[i], s) != 0; ++i);
    for (j = 1; strcmp(cities[j], t) != 0; ++j);
    printf("%d\n", graph_dijkstra(graph, i, j));
  }
  graph_free(&graph);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
