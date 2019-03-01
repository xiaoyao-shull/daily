#include <stdio.h>
#include <string.h>

#define MAX_NODE_COUNT 100000
#define MAX_EDGE_COUNT 99999
int node_edge[MAX_NODE_COUNT + 1];
int edge_head[MAX_EDGE_COUNT * 2 + 1];
int edge_next[MAX_EDGE_COUNT * 2 + 1];
int states1[MAX_NODE_COUNT + 1];
int states2[MAX_NODE_COUNT + 1];
int node_visited[MAX_NODE_COUNT + 1];

int min(int x, int y) {
  return x < y ? x : y;
}

/**
 * @return 0 if u is leaf, 1 otherwise.
 */
int dfs(int u) {
  int i;
  int v;
  int state1 = 1;
  int state2 = 0;
  node_visited[u] = 1;
  for (i = node_edge[u]; i != 0; i = edge_next[i]) {
    v = edge_head[i];
    if (node_visited[v]) {
      continue;
    }
    if (dfs(v)) {
      state1 += min(states1[v], states2[v]);
      state2 += states1[v];

    } else {
      state1 += 0;
      state2 += states1[v];
    }
  }
  if (state1 == 0 && state2 == 0) {
    states1[u] = 1;
    return 0;

  } else {
    states1[u] = state1;
    states2[u] = state2;
    return 1;
  }
}

int main(int argc, char * argv[]) {
  int node_count;
  int edge_count;
  int i;
  int u, v;
  while (scanf("%d", &node_count) > 0) {
    edge_count = 0;
    memset(node_edge, 0, sizeof(node_edge));
    memset(edge_next, 0, sizeof(edge_next));
    memset(states1, -1, sizeof(states1));
    memset(states2, -1, sizeof(states2));
    memset(node_visited, 0, sizeof(node_visited));
    for (i = 1; i <= node_count - 1; ++i) {
      scanf("%d%d", &u, &v);
      edge_count++;
      edge_head[edge_count] = v;
      edge_next[edge_count] = node_edge[u];
      node_edge[u] = edge_count;

      edge_count++;
      edge_head[edge_count] = u;
      edge_next[edge_count] = node_edge[v];
      node_edge[v] = edge_count;
    }
    dfs(1);
    printf("%d\n", min(states1[1], states2[1]));
  }
  return 0;
}
