#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 4000
#define MAX_EDGE_COST 100

int edge_head[MAX_EDGE_COUNT * 2 + 1];
int edge_next[MAX_EDGE_COUNT * 2 + 1];
int edge_cost[MAX_EDGE_COUNT * 2 + 1];

int node_edge[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];
int node_dist[MAX_NODE_COUNT + 1];

int bucket_prev[MAX_NODE_COUNT + 1];
int bucket_next[MAX_NODE_COUNT + 1];
int bucket_root[MAX_EDGE_COST + 1];

void bucket_del(int u);
void bucket_add(int u);

int main(int argc, char * argv[]) {
  int i, j, k;
  int u, v, w;
  int edge_count, node_count;
  scanf("%d%d", &edge_count, &node_count);

  memset(edge_next, 0, sizeof(edge_next));
  memset(node_edge, 0, sizeof(node_edge));
  memset(node_mark, 0, sizeof(node_mark));
  memset(bucket_root, 0, sizeof(bucket_root));
  memset(bucket_prev, 0, sizeof(bucket_prev));
  memset(bucket_next, 0, sizeof(bucket_next));
  for (i = 1; i <= node_count; ++i) {
    node_dist[i] = (i == 1) ? 0 : -1;
  }

  for (i = 0, j = 0; i < edge_count; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    if (u == v) {
      continue;
    }

    j++;
    edge_head[j] = v;
    edge_cost[j] = w;
    edge_next[j] = node_edge[u];
    node_edge[u] = j;

    j++;
    edge_head[j] = u;
    edge_cost[j] = w;
    edge_next[j] = node_edge[v];
    node_edge[v] = j;
  }

  bucket_add(1);
  i = 0;
  j = 0;
  while (1) {
    if (bucket_root[i] == 0) {
      i = (i + 1) % (MAX_EDGE_COST + 1);
      continue;
    }
    while (bucket_root[i] != 0) {
      u = bucket_root[i];
      bucket_del(u);
      for (k = node_edge[u]; k != 0; k = edge_next[k]) {
        v = edge_head[k];
        w = edge_cost[k];
        if (node_dist[v] == -1) {
          node_dist[v] = node_dist[u] + w;
          bucket_add(v);

        } else if (node_dist[v] > node_dist[u] + w) {
          bucket_del(v);
          node_dist[v] = node_dist[u] + w;
          bucket_add(v);
        }
      }
      if (u == node_count) {
        j = 1;
      }
    }
    if (j == 1) {
      break;
    }
  }
  printf("%d\n", node_dist[node_count]);
  return 0;
}

void bucket_del(int u) {
  int x = node_dist[u] % (MAX_EDGE_COST + 1);
  if (bucket_prev[u] != 0) {
    bucket_next[bucket_prev[u]] = bucket_next[u];
  }
  if (bucket_next[u] != 0) {
    bucket_prev[bucket_next[u]] = bucket_prev[u];
  }
  if (bucket_root[x] == u) {
    bucket_root[x] = bucket_next[u] != 0 ? bucket_next[u] : bucket_prev[u];
  }
  bucket_prev[u] = 0;
  bucket_next[u] = 0;
}

void bucket_add(int u) {
  int x = node_dist[u] % (MAX_EDGE_COST + 1);
  if (bucket_root[x] != 0) {
    bucket_prev[bucket_root[x]] = u;
    bucket_next[u] = bucket_root[x];
    bucket_root[x] = u;

  } else {
    bucket_root[x] = u;
  }
}
