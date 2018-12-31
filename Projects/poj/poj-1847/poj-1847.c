#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 100
#define MAX_EDGE_COUNT 9900

int edge_head[MAX_EDGE_COUNT + 1];
int edge_cost[MAX_EDGE_COUNT + 1];
int edge_next[MAX_EDGE_COUNT + 1];
int node_edge[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];
int node_dist[MAX_NODE_COUNT + 1];

int main(int argc, char * argv[]) {
  int s, t;
  int i, j, k;
  int u, v, w;
  int node_count;
  int edge_count = 0;
  memset(node_mark, 0, sizeof(node_mark));
  memset(node_edge, 0, sizeof(node_edge));
  memset(edge_next, 0, sizeof(edge_next));
  scanf("%d%d%d", &node_count, &s, &t);
  for (i = 1; i <= node_count; ++i) {
    scanf("%d", &j);
    for (k = 0; k < j; ++k) {
      scanf("%d", &v);
      edge_count++;
      edge_head[edge_count] = v;
      edge_cost[edge_count] = (k == 0) ? 0 : 1;
      edge_next[edge_count] = node_edge[i];
      node_edge[i] = edge_count;
    }
    node_dist[i] = (i == s) ? 0 : -1;
  }
  while (node_mark[t] == 0) {
    for (i = 1, j = 0; i <= node_count; ++i) {
      if (node_mark[i] || node_dist[i] == -1) {
        continue;
      }
      if (j == 0 || node_dist[j] > node_dist[i]) {
        j = i;
      }
    }
    if (j == 0) {
      break;
    }
    node_mark[j] = 1;
    for (i = node_edge[j]; i != 0; i = edge_next[i]) {
      v = edge_head[i];
      w = edge_cost[i];
      if (node_dist[v] == -1 || node_dist[v] > node_dist[j] + w) {
        node_dist[v] = node_dist[j] + w;
      }
    }
  }
  printf("%d\n", node_mark[t] == 1 ? node_dist[t] : -1);
  return 0;
}
