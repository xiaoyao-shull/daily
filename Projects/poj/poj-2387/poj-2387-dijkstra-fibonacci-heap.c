#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fibnode_t {
  int key;
  int value;
  int marked;
  int degree;
  struct fibnode_t * left;
  struct fibnode_t * right;
  struct fibnode_t * parent;
  struct fibnode_t * children;
};

struct fibheap_t {
  struct fibnode_t * root;
};

typedef struct fibheap_t * fibheap_t;
typedef struct fibnode_t * fibnode_t;

fibnode_t fibnode_make(int key, int value) {
  struct fibnode_t * ptr = malloc(sizeof(*ptr));
  ptr->key = key;
  ptr->value = value;
  ptr->left = ptr;
  ptr->right = ptr;
  ptr->parent = NULL;
  ptr->children = NULL;
  ptr->marked = 0;
  ptr->degree = 0;
  return ptr;
}

fibheap_t fibheap_make() {
  struct fibheap_t * ptr = malloc(sizeof(*ptr));
  ptr->root = NULL;
  return ptr;
}

void fibheap_free(fibheap_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void fibnode_hcat(fibnode_t list, fibnode_t node) {
  if (node == NULL) {
    return;
  }
  list->left->right = node;
  node->left = list->left;
  list->left = node;
  node->right = list;
}

void fibnode_hcut(fibnode_t node) {
  if (node == NULL) {
    return;
  }
  node->left->right = node->right;
  node->right->left = node->left;
}

void fibnode_vcut(fibnode_t node) {
  if (node == NULL) {
    return;
  }
  if (node->parent == NULL) {
    node->left = node;
    node->right = node;
    return;

  } else {
    if (node->parent->children == node) {
      if (node->left == node) {
        node->parent->children = NULL;

      } else {
        node->parent->children = node->left;
      }
    }
    node->parent->degree--;
    node->parent = NULL;
    node->left = node;
    node->right = node;
  }
}

void fibnode_vcat(fibnode_t sup, fibnode_t sub) {
  sup->degree++;
  sub->marked = 0;
  sub->parent = sup;
  if (sup->children == NULL) {
    sup->children = sub;
  } else {
    fibnode_hcat(sup->children, sub);
  }
}

void fibheap_cat(fibheap_t heap, fibnode_t node) {
  if (heap->root == NULL) {
    heap->root = node;

  } else {
    fibnode_hcat(heap->root, node);
  }
  if (heap->root->key > node->key) {
    heap->root = node;
  }
}

void fibheap_cut(fibheap_t heap, fibnode_t node, int cascading) {
  fibnode_t next_node = node;
  while (next_node != NULL && next_node->parent != NULL) {
    node = next_node;
    if (cascading && node->parent->parent != NULL) {
      if (node->parent->marked) {
        node->parent->marked = 0;
        next_node = node->parent;

      } else {
        node->parent->marked = 1;
        next_node = NULL;
      }
    }

    fibnode_hcut(node);
    fibnode_vcut(node);
    fibheap_cat(heap, node);
  }
}

void fibheap_delete_min(fibheap_t heap) {
  fibnode_t bucket[32];
  fibnode_t node;
  int degree;
  int i;
  if (heap->root == NULL) {
    return;
  }
  while (heap->root->children != NULL) {
    fibheap_cut(heap, heap->root->children, 0);
  }
  if (heap->root->left == heap->root) {
    free(heap->root);
    heap->root = NULL;
    return;
  }
  node = heap->root;
  heap->root = heap->root->left;
  fibnode_hcut(node);
  free(node);

  memset(bucket, 0, sizeof(bucket));
  for (node = heap->root; node != NULL; node = heap->root) {
    fibnode_hcut(node);
    if (node->left == node) {
      heap->root = NULL;
    } else {
      heap->root = node->left;
    }
    node->left = node;
    node->right = node;

    degree = node->degree;
    while (bucket[degree] != NULL) {
      if (node->key < bucket[degree]->key) {
        fibnode_vcat(node, bucket[degree]);

      } else {
        fibnode_vcat(bucket[degree], node);
        node = bucket[degree];
      }
      bucket[degree] = NULL;
      degree++;
    }
    bucket[degree] = node;
  }
  for (i = 0; i < 32; ++i) {
    if (bucket[i] != NULL) {
      fibheap_cat(heap, bucket[i]);
    }
  }
}
fibnode_t fibheap_insert(fibheap_t heap, int key, int value) {
  fibnode_t node = fibnode_make(key, value);
  fibheap_cat(heap, node);
  return node;
}

void fibheap_decrease_key(fibheap_t heap, fibnode_t node, int delta) {
  node->key -= delta;
  if (node->parent != NULL) {
    fibheap_cut(heap, node, 1);

  } else if (heap->root->key > node->key) {
    heap->root = node;
  }
}

int fibheap_find_min(fibheap_t heap) {
  return heap->root->value;
}
#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 4000

int edge_head[MAX_EDGE_COUNT * 2 + 1];
int edge_next[MAX_EDGE_COUNT * 2 + 1];
int edge_cost[MAX_EDGE_COUNT * 2 + 1];

int node_heap[MAX_NODE_COUNT + 1];
int node_edge[MAX_NODE_COUNT + 1];
int node_dist[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];


int main(int argc, char * argv[]) {
  int edge_count;
  int node_count;
  int i, j, k;
  int u, v, w;
  fibheap_t fibheap;
  fibnode_t fibnodes[MAX_NODE_COUNT + 1];

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
  memset(fibnodes, 0, sizeof(fibnodes));
  for (i = 1; i <= node_count; ++i) {
    node_dist[i] = i == 1 ? 0 : -1;
  }
  fibheap = fibheap_make();
  fibnodes[1] = fibheap_insert(fibheap, 0, 1);

  while (1) {
    j = fibheap_find_min(fibheap);
    fibheap_delete_min(fibheap);
    node_mark[j] = 1;
    for (i = node_edge[j]; i != 0; i = edge_next[i]) {
      k = edge_head[i];
      if (node_dist[k] == -1) {
        node_dist[k] = node_dist[j] + edge_cost[i];
        fibnodes[k] = fibheap_insert(fibheap, node_dist[k], k);

      } else if (node_dist[k] > node_dist[j] + edge_cost[i]) {
        fibheap_decrease_key(fibheap, fibnodes[k], node_dist[k] - edge_cost[i] - node_dist[j]);
        node_dist[k] = node_dist[j] + edge_cost[i];
      }
    }
    if (j == node_count) {
      break;
    }
  }

  printf("%d\n", node_dist[node_count]);
  return 0;
}
