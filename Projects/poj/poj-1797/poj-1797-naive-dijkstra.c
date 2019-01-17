#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 1000

int node_dist[MAX_NODE_COUNT + 1];
int node_mark[MAX_NODE_COUNT + 1];
int adjacent_matrix[(MAX_NODE_COUNT + 1) * (MAX_NODE_COUNT + 1)];

void clear() {
  memset(adjacent_matrix, -1, sizeof(adjacent_matrix));
  memset(node_dist, -1, sizeof(node_dist));
  memset(node_mark, 0, sizeof(node_mark));
}

int is_marked(int node) {
  return node_mark[node];
}

void set_marked(int node) {
  node_mark[node] = 1;
}

int get_dist(int node) {
  return node_dist[node];
}

void set_dist(int node, int dist) {
  node_dist[node] = dist;
}

int has_dist(int node) {
  return node_dist[node] >= 0;
}

void set_len(int row, int col, int len) {
  adjacent_matrix[row * (MAX_NODE_COUNT + 1) + col] = len;
}

int get_len(int row, int col) {
  return adjacent_matrix[row * (MAX_NODE_COUNT + 1) + col];
}

int has_len(int row, int col) {
  return adjacent_matrix[row * (MAX_NODE_COUNT + 1) + col] >= 0;
}

int min_2(int x, int y) {
  return x < y ? x : y;
}

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  int node_count;
  int edge_count;
  int u, v, p;
  int i, j, k;
  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    clear();
    scanf("%d%d", &node_count, &edge_count);
    for (i = 0; i < edge_count; ++i) {
      scanf("%d%d%d", &u, &v, &p);
      if (has_len(u, v) && get_len(u, v) > p) {
        continue;
      }
      set_len(u, v, p);
      set_len(v, u, p);
    }
    set_dist(1, INT_MAX);
    while (!is_marked(node_count)) {
      for (i = 1, j = 0; i <= node_count; ++i) {
        if (is_marked(i) || !has_dist(i)) {
          continue;
        }
        if (j == 0 || get_dist(j) < get_dist(i)) {
          j = i;
        }
      }
      set_marked(j);
      for (i = 1; i <= node_count; ++i) {
        if (i == j || is_marked(i) || !has_len(j, i)) {
          continue;
        }
        p = min_2(get_dist(j), get_len(j, i));
        if (!has_dist(i) || get_dist(i) < p) {
          set_dist(i, p);
        }
      }
    }
    printf("Scenario #%d:\n", case_index);
    printf("%d\n\n", get_dist(node_count));
  }
  return 0;
}
