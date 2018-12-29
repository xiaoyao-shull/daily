#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 4000
#define INCOMPARABLE_INFINITY -1

int edge_head[2 * MAX_EDGE_COUNT + 1];
int edge_tail[2 * MAX_EDGE_COUNT + 1];
int edge_cost[2 * MAX_EDGE_COUNT + 1];
int edge_next_f[2 * MAX_EDGE_COUNT + 1];
int edge_next_b[2 * MAX_EDGE_COUNT + 1];

int node_edge_f[MAX_NODE_COUNT + 1];
int node_edge_b[MAX_NODE_COUNT + 1];
int node_dist_f[MAX_NODE_COUNT + 1];
int node_dist_b[MAX_NODE_COUNT + 1];
int node_mark_f[MAX_NODE_COUNT + 1];
int node_mark_b[MAX_NODE_COUNT + 1];

int main(int argc, char * argv[]) {
  int edge_count;
  int node_count;
  int i, j, k;
  int u, v, w;
  int shortest_path_length = INCOMPARABLE_INFINITY;

  scanf("%d%d", &edge_count, &node_count);
  memset(node_edge_f, 0, sizeof(node_edge_f));
  memset(node_edge_b, 0, sizeof(node_edge_b));
  for (i = 0, j = 0; i < edge_count; ++i) {
    scanf("%d%d%d", &u, &v, &w);

    j++;
    edge_head[j] = v;
    edge_tail[j] = u;
    edge_cost[j] = w;
    edge_next_f[j] = node_edge_f[u];
    node_edge_f[u] = j;
    edge_next_b[j] = node_edge_b[v];
    node_edge_b[v] = j;

    j++;
    edge_head[j] = u;
    edge_tail[j] = v;
    edge_cost[j] = w;
    edge_next_f[j] = node_edge_f[v];
    node_edge_f[v] = j;
    edge_next_b[j] = node_edge_b[u];
    node_edge_b[u] = j;
  }


  for (i = 1; i <= node_count; ++i) {
    node_dist_f[i] = i == 1 ? 0 : INCOMPARABLE_INFINITY;
    node_dist_b[i] = i == node_count ? 0 : INCOMPARABLE_INFINITY;
  }

  memset(node_mark_f, 0, sizeof(node_mark_f));
  memset(node_mark_b, 0, sizeof(node_mark_b));
  while (1) {
    // forward dijkstra.
    for (i = 1, j = 0; i <= node_count; ++i) {
      if (node_mark_f[i] != 0 || node_dist_f[i] == INCOMPARABLE_INFINITY) {
        continue;
      }
      if (j == 0 || node_dist_f[j] > node_dist_f[i]) {
        j = i;
      }
    }
    node_mark_f[j] = 1;
    for (i = node_edge_f[j]; i != 0; i = edge_next_f[i]) {
      u = edge_tail[i];
      v = edge_head[i];
      w = edge_cost[i];
      if (node_dist_f[v] == INCOMPARABLE_INFINITY || node_dist_f[v] > node_dist_f[u] + w) {
        node_dist_f[v] = node_dist_f[u] + w;
      }
      if (node_mark_b[v] != 0) {
        if (shortest_path_length == INCOMPARABLE_INFINITY || shortest_path_length > node_dist_f[u] + w + node_dist_b[v]) {
          shortest_path_length = node_dist_f[u] + w + node_dist_b[v];
        }
      }
    }
    if (node_mark_b[j] != 0) {
      break;
    }

    // backward dijkstra.
    for (i = 1, j = 0; i <= node_count; ++i) {
      if (node_mark_b[i] != 0 || node_dist_b[i] == INCOMPARABLE_INFINITY) {
        continue;
      }
      if (j == 0 || node_dist_b[j] > node_dist_b[i]) {
        j = i;
      }
    }
    node_mark_b[j] = 1;
    for (i = node_edge_b[j]; i != 0; i = edge_next_b[i]) {
      u = edge_tail[i];
      v = edge_head[i];
      w = edge_cost[i];
      if (node_dist_b[u] == INCOMPARABLE_INFINITY || node_dist_b[u] > node_dist_b[v] + w) {
        node_dist_b[u] = node_dist_b[v] + w;
      }
      if (node_mark_f[u] != 0) {
        if (shortest_path_length == INCOMPARABLE_INFINITY || shortest_path_length > node_dist_b[v] + w + node_dist_f[u]) {
          shortest_path_length = node_dist_b[v] + w + node_dist_f[u];
        }
      }
    }
    if (node_mark_f[j] != 0) {
      break;
    }
  }
  printf("%d\n", shortest_path_length);
  return 0;
}
