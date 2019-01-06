#include <stdio.h>
#include <string.h>

#define MAX_NODE_COUNT 10000
#define MAX_EDGE_COUNT 20000

int edge_tail[MAX_EDGE_COUNT + 1];
int edge_head[MAX_EDGE_COUNT + 1];
int node_next[MAX_NODE_COUNT + 1];

int get_root(int node) {
  while (node_next[node] != 0) {
    node = node_next[node];
  }
  return node;
}

int main(int argc, char * argv[]) {
  int node_count;
  int edge_count;
  int i;
  int u, v;
  scanf("%d%d", &node_count, &edge_count);
  for (i = 1; i <= edge_count; ++i) {
    scanf("%d%d", &edge_tail[i], &edge_head[i]);
  }
  if (edge_count != node_count - 1) {
    printf("NO\n");

  } else {
    memset(node_next, 0, sizeof(node_next));
    for (i = 1; i <= edge_count; ++i) {
      u = get_root(edge_tail[i]);
      v = get_root(edge_head[i]);
      if (u == v) {
        break;
      }
      node_next[u] = v;
    }
    if (i > edge_count) {
      printf("YES\n");

    } else {
      printf("NO\n");
    }
  }
  return 0;
}
