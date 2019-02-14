#include <stdio.h>
#include <string.h>

#define MAX_NODE_COUNT 100000
#define MAX_EDGE_COUNT 100000
int node_edge[MAX_NODE_COUNT];
int edge_next[MAX_EDGE_COUNT];
int edge_head[MAX_EDGE_COUNT];
int node_flag[MAX_NODE_COUNT];

void dfs(int i) {
  int j;
  if (node_flag[i] == 1) {
    return;
  }
  node_flag[i] = 1;
  for (j = node_edge[i]; j != -1; j = edge_next[j]) {
    dfs(edge_head[j]);
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  int node_count;
  int edge_count;
  int i, j, k;
  int u, v, w;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &node_count);
    scanf("%d", &i);
    memset(node_edge, -1, sizeof(node_edge));
    memset(edge_next, -1, sizeof(edge_next));
    edge_count = 0;
    while (i--) {
      scanf("%d%d", &u, &v);
      edge_head[edge_count] = v;
      edge_next[edge_count] = node_edge[u];
      node_edge[u] = edge_count;
      edge_count++;

      edge_head[edge_count] = u;
      edge_next[edge_count] = node_edge[v];
      node_edge[v] = edge_count;
      edge_count++;
    }
    memset(node_flag, 0, sizeof(node_flag));
    for (i = 0, j = 0; i < node_count; ++i) {
      if (node_flag[i] == 0) {
        j++;
        dfs(i);
      }
    }
    printf("%d\n", j);
  }
  return 0;
}
