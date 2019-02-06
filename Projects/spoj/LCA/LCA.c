#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 999

int node_edge_1[MAX_NODE_COUNT + 1];
int node_edge_2[MAX_NODE_COUNT + 1];
int edge_tail[MAX_EDGE_COUNT + 1];
int edge_head[MAX_EDGE_COUNT + 1];
int edge_next_1[MAX_EDGE_COUNT + 1];
int edge_next_2[MAX_EDGE_COUNT + 1];
int node_height[MAX_NODE_COUNT + 1];

void get_height(int node, int height) {
  int i;
  int v;
  node_height[node] = height;
  for (i = node_edge_1[node]; i != 0; i = edge_next_1[i]) {
    v = edge_head[i];
    get_height(v, height + 1);
  }
}

void run(int case_index) {
  int node_count;
  int edge_count;
  int query_count;
  int u, v;
  int i;
  memset(node_edge_1, 0, sizeof(node_edge_1));
  memset(node_edge_2, 0, sizeof(node_edge_2));
  memset(edge_next_1, 0, sizeof(edge_next_1));
  memset(edge_next_2, 0, sizeof(edge_next_2));
  edge_count = 0;
  scanf("%d", &node_count);
  for (u = 1; u <= node_count; ++u) {
    scanf("%d", &i);
    while (i--) {
      scanf("%d", &v);
      edge_count++;
      edge_tail[edge_count] = u;
      edge_head[edge_count] = v;
      edge_next_1[edge_count] = node_edge_1[u];
      node_edge_1[u] = edge_count;
      edge_next_2[edge_count] = node_edge_2[v];
      node_edge_2[v] = edge_count;
    }
  }

  for (u = 1; u < node_count; ++u) {
    if (node_edge_2[u] == 0) {
      break;
    }
  }
  get_height(u, 1);

  scanf("%d", &query_count);
  printf("Case %d:\n", case_index);
  while (query_count--) {
    scanf("%d%d", &u, &v);
    while (node_height[u] != node_height[v]) {
      if (node_height[u] > node_height[v]) {
        u = edge_tail[node_edge_2[u]];

      } else {
        v = edge_tail[node_edge_2[v]];
      }
    }
    while (u != v) {
      u = edge_tail[node_edge_2[u]];
      v = edge_tail[node_edge_2[v]];
    }
    printf("%d\n", u);
  }
  return;
}

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    run(case_index);
  }
  return 0;
}
