#include <stdio.h>

int o2_count;
int n2_count;
int tank_count;

#define MAX_O2_COUNT 21
#define MAX_N2_COUNT 79
#define MAX_TANK_COUNT 1000

int tank_o2[MAX_TANK_COUNT];
int tank_n2[MAX_TANK_COUNT];
int tank_weight[MAX_TANK_COUNT];
int state[MAX_TANK_COUNT + 1][MAX_O2_COUNT + 1][MAX_N2_COUNT + 1];

int max(int x, int y) {
  return x > y ? x : y;
}

int dp(int tank_index, int o2_count, int n2_count) {
  if (o2_count == 0 && n2_count == 0) {
      return 0;
  }
  if (tank_index <= 0) {
      return -2;
  }
  if (state[tank_index][o2_count][n2_count] != -1) {
    return state[tank_index][o2_count][n2_count];
  }
  int min_weight = -2;
  int weight;
  weight = dp(tank_index - 1, max(0, o2_count - tank_o2[tank_index]), max(0, n2_count - tank_n2[tank_index]));
  if (weight != -2) {
    min_weight = weight + tank_weight[tank_index];
  }
  weight = dp(tank_index - 1, o2_count, n2_count);
  if (weight != -2) {
    if (min_weight == -2 || min_weight > weight) {
      min_weight = weight;
    }
  }
  state[tank_index][o2_count][n2_count] = min_weight;
  return min_weight;
}

void run() {
  int i, j, k;
  scanf("%d%d", &o2_count, &n2_count);
  scanf("%d", &tank_count);
  for (i = 1; i <= tank_count; ++i) {
    scanf("%d%d%d", &tank_o2[i], &tank_n2[i], &tank_weight[i]);
  }
  for (i = 1; i <= tank_count; ++i) {
    for (j = 0; j <= o2_count; ++j) {
      for (k = 0; k <= n2_count; ++k) {
        state[i][j][k] = -1;
      }
    }
  }
  printf("%d\n", dp(tank_count, o2_count, n2_count));
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
