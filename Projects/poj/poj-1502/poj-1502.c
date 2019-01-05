#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 100
#define MAX_EDGE_COUNT 4950

int edge_cost[MAX_EDGE_COUNT + 1];
int edge_next[MAX_EDGE_COUNT + 1];
int edge_head[MAX_EDGE_COUNT + 1];
int node_edge[MAX_NODE_COUNT + 1];

int node_dist[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];

int main(int argc, char * argv[]) {
  int node_count;
  int edge_count = 0;
  int i, j, k;
  int u, v, w;
  char buffer[64];
  memset(edge_next, 0, sizeof(edge_next));
  memset(node_edge, 0, sizeof(node_edge));
  memset(node_mark, 0, sizeof(node_mark));
  memset(node_dist, -1, sizeof(node_dist));
  scanf("%d", &node_count);
  node_dist[1] = 0;
  for (i = 2; i <= node_count; ++i) {
    for (j = 1; j < i; ++j) {
      scanf("%s", buffer);
      if (strcmp(buffer, "x") == 0) {
        continue;
      }
      k = (int) strtol(buffer, NULL, 10);

      edge_cost[edge_count] = k;
      edge_head[edge_count] = j;
      edge_next[edge_count] = node_edge[i];
      node_edge[i] = edge_count;
      edge_count++;

      edge_cost[edge_count] = k;
      edge_head[edge_count] = i;
      edge_next[edge_count] = node_edge[j];
      node_edge[j] = edge_count;
      edge_count++;
    }
  }

  while (1) {
    for (i = 1, u = 0; i <= node_count; ++i) {
      if (node_mark[i] > 0) {
        continue;
      }
      if (node_dist[i] == -1) {
        continue;
      }
      if (u == 0 || node_dist[u] > node_dist[i]) {
        u = i;
      }
    }
    if (u == 0) {
      break;
    }
    node_mark[u] = 1;
    for (i = node_edge[u]; i != 0; i = edge_next[i]) {
      v = edge_head[i];
      w = edge_cost[i];
      if (node_dist[v] == -1 || node_dist[v] > node_dist[u] + w) {
        node_dist[v] = node_dist[u] + w;
      }
    }
  }
  for (i = 2, j = node_dist[1]; i <= node_count; ++i) {
    if (j < node_dist[i]) {
      j = node_dist[i];
    }
  }
  printf("%d\n", j);
  return 0;
}
