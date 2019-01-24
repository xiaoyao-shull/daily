#include <stdio.h>

#define MAX_ROW_COUNT 100
#define MAX_COL_COUNT 100
int row_count;
int col_count;
int fare[MAX_ROW_COUNT][MAX_COL_COUNT];
int state[MAX_ROW_COUNT][MAX_COL_COUNT];

int dp(int row, int col) {
  if (state[row][col] != -1) {
    return state[row][col];
  }
  if (row == row_count - 1) {
    state[row][col] = fare[row][col];
    return fare[row][col];
  }
  int min_fare = fare[row][col] + dp(row + 1, col);
  int new_fare;
  if (col - 1 >= 0) {
    new_fare = fare[row][col] + dp(row + 1, col - 1);
    if (min_fare > new_fare) {
      min_fare = new_fare;
    }
  }
  if (col + 1 < col_count) {
    new_fare = fare[row][col] + dp(row + 1, col + 1);
    if (min_fare > new_fare) {
      min_fare = new_fare;
    }
  }
  state[row][col] = min_fare;
  return min_fare;
}

int main(int argc, char * argv[]) {
  int i, j;
  scanf("%d%d", &row_count, &col_count);
  for (i = 0; i < row_count; ++i) {
    for (j = 0; j < col_count; ++j) {
      scanf("%d", &fare[i][j]);
      state[i][j] = -1;
    }
  }
  for (j = 0; j < col_count; ++j) {
    dp(0, j);
  }
  for (i = state[0][0], j = 1; j < col_count; ++j) {
    if (i > state[0][j]) {
      i = state[0][j];
    }
  }
  printf("%d\n", i);
  return 0;
}
