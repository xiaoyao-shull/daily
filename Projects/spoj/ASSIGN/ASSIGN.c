#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20
#define BITMASK_COUNT (1024 * 1024)

long long state[MAX_SIZE * BITMASK_COUNT];
int likes[MAX_SIZE][MAX_SIZE];

long long calc_state(int x, int y, int n) {
  int i;
  long long s;
  if (x >= n) {
    return 1L;
  }
  if ((s = state[x * BITMASK_COUNT + y]) == -1) {
    for (i = 0, s = 0L; i < n; ++i) {
      if (likes[x][i] && (y & (1 << i)) == 0) {
        s += calc_state(x + 1, y | (1 << i), n);
      }
    }
    state[x * BITMASK_COUNT + y] = s;
  }
  return s;
}

int main(int argc, char * argv[]) {
  int case_count;
  int n;
  int i, j;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        scanf("%d", &likes[i][j]);
      }
    }
    memset(state, -1, sizeof(state));
    printf("%lld\n", calc_state(0, 0, n));
  }
  return 0;
}
