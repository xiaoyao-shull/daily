#include <stdio.h>

#define MAX_N 1000

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }

int main(int argc, char * argv[]) {
  int n;
  int card[MAX_N];
  int state[MAX_N][MAX_N];
  int i;
  int x, y;
  int u, v;
  int t = 0;
  while (scanf("%d", &n), n > 0) {
    for (i = 0; i < n; ++i) {
      scanf("%d", &card[i]);
    }

    for (x = 0; x + 1 < n; ++x) {
      y = x + 1;
      state[x][y] = max(card[x], card[y]) - min(card[x], card[y]);
    }

    for (i = 3; i < n; i += 2) {
      for (x = 0; x + i < n; ++x) {
        y = x + i;

        u = card[x + 1] >= card[y]
          ? card[x] - card[x + 1] + state[x + 2][y]
          : card[x] - card[y] + state[x + 1][y - 1];

        v = card[x] >= card[y - 1]
          ? card[y] - card[x] + state[x + 1][y - 1]
          : card[y] - card[y - 1] + state[x][y - 2];

        state[x][y] = max(u, v);
      }
    }
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ++t, state[0][n - 1]);
  }
  return 0;
}
