#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 4000

int edge_head[2 * MAX_EDGE_COUNT + 1];
int edge_next[2 * MAX_EDGE_COUNT + 1];
int edge_cost[2 * MAX_EDGE_COUNT + 1];

int node_edge[MAX_NODE_COUNT + 1];
int node_dist[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];

int main(int argc, char * argv[]) {
  int edge_count;
  int node_count;
  int i, j, k;
  int u, v, w;

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

  memset(node_mark, 0, sizeof(node_mark));
  for (i = 1; i <= node_count; ++i) {
    node_dist[i] = i == 1 ? 0 : -1;
  }

  while (node_mark[node_count] == 0) {
    for (i = 1, j = 0; i <= node_count; ++i) {
      if (node_mark[i] != 0 || node_dist[i] == -1) {
        continue;
      }
      if (j == 0 || node_dist[i] < node_dist[j]) {
        j = i;
      }
    }
    node_mark[j] = 1;
    for (i = node_edge[j]; i != 0; i = edge_next[i]) {
      k = edge_head[i];
      if (node_dist[k] == -1 || node_dist[k] > node_dist[j] + edge_cost[i]) {
        node_dist[k] = node_dist[j] + edge_cost[i];
      }
    }
  }

  printf("%d\n", node_dist[node_count]);
  return 0;
}
