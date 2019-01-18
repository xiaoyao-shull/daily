#include <stdio.h>
#include <string.h>

int is_composite[10000];

int diff(int x, int y) {
  int x1 = x % 10;
  int x2 = (x / 10) % 10;
  int x3 = (x / 100) % 10;
  int x4 = (x / 1000) % 10;

  int y1 = y % 10;
  int y2 = (y / 10) % 10;
  int y3 = (y / 100) % 10;
  int y4 = (y / 1000) % 10;

  return (x1 != y1) + (x2 != y2) + (x3 != y3) + (x4 != y4);
}

void init_prime() {
  int i, j;
  memset(is_composite, 0, sizeof(is_composite));
  for (i = 2; i <= 5000; ++i) {
    for (j = i * 2; j < 10000; j += i) {
      is_composite[j] = 1;
    }
  }
}

int node_edge[10000];
int edge_head[10000];
int edge_next[10000];

void init_graph() {
  int i, j, k;
  memset(node_edge, 0, sizeof(node_edge));
  memset(edge_next, 0, sizeof(node_edge));
  for (i = 2; i <= 5000; ++i) {
    for (j = i * 2; j < 10000; j += i) {
      is_composite[j] = 1;
    }
  }
  for (i = 1000, k = 0; i <= 9999; ++i) {
    for (j = i + 1; j <= 9999; ++j) {
      if (is_composite[i] || is_composite[j]) {
        continue;
      }
      if (diff(i, j) == 1) {
        k++;
        edge_head[k] = j;
        edge_next[k] = node_edge[i];
        node_edge[i] = k;

        k++;
        edge_head[k] = i;
        edge_next[k] = node_edge[j];
        node_edge[j] = k;
      }
    }
  }
}

int node_mark[10000];
int node_dist[10000];
int dijkstra(int s, int t) {
  int i, j, k;
  memset(node_mark, 0, sizeof(node_mark));
  memset(node_dist, -1, sizeof(node_dist));
  node_dist[s] = 0;
  while (node_mark[t] == 0) {
    for (i = 1000, j = -1; i <= 9999; ++i) {
      if (node_mark[i] || node_dist[i] == -1) {
        continue;
      }
      if (j == -1 || node_dist[j] > node_dist[i]) {
        j = i;
      }
    }
    if (j == -1) {
      return -1;
    }
    node_mark[j] = 1;
    for (i = node_edge[j]; i != 0; i = edge_next[i]) {
      k = edge_head[i];
      if (node_dist[k] == -1 || node_dist[k] > node_dist[j] + 1) {
        node_dist[k] = node_dist[j] + 1;
      }
    }
  }
  return node_dist[t];
}

int main(int argc, char * argv[]) {
  int case_count;
  int s, t;
  int p;
  init_prime();
  init_graph();
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &s, &t);
    p = dijkstra(s, t);
    if (p == -1) {
      printf("Impossible\n");

    } else {
      printf("%d\n", p);
    }
  }
  return 0;
}
