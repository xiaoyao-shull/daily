#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 200
int x[MAX_NODE_COUNT + 1];
int y[MAX_NODE_COUNT + 1];
int d[MAX_NODE_COUNT + 1];
int m[MAX_NODE_COUNT + 1];

int max(int x, int y) {
  return x > y ? x : y;
}

int main(int argc, char * argv[]) {
  int case_index = 1;
  int node_count;
  int i, j, k;
  int u, v, w;
  while (1) {
    scanf("%d", &node_count);
    if (node_count == 0) {
      break;
    }
    for (i = 1; i <= node_count; ++i) {
      scanf("%d%d", &j, &k);
      x[i] = j;
      y[i] = k;
      if (i == 1) {
        d[i] = 0;
        m[i] = 1;

      } else {
        u = j - x[1];
        v = k - y[1];
        d[i] = u * u + v * v;
        m[i] = 0;
      }
    }
    while (m[2] == 0) {
      for (i = 1, j = 0; i <= node_count; ++i) {
        if (m[i] == 1) {
          continue;
        }
        if (j == 0 || d[j] > d[i]) {
          j = i;
        }
      }
      m[j] = 1;
      for (i = 1; i <= node_count; ++i) {
        if (i == j || m[i] == 1) {
          continue;
        }
        u = x[i] - x[j];
        v = y[i] - y[j];
        w = max(d[j], u * u + v * v);
        if (d[i] > w) {
          d[i] = w;
        }
      }
    }
    printf("Scenario #%d\n", case_index++);
    printf("Frog Distance = %.3f\n", sqrt(d[2]));
    printf("\n");
  }
  return 0;
}
