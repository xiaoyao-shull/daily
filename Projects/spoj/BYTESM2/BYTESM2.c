#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100

int stone[MAX_ROW][MAX_COL];
int state[MAX_ROW][MAX_COL];

int max_2(int x, int y) {
  return x > y ? x : y;
}

int max_3(int x, int y, int z) {
  return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

void run() {
  int row;
  int col;
  int i, j, k;
  scanf("%d%d", &row, &col);
  for (i = 0; i < row; ++i) {
    for (j = 0; j < col; ++j) {
      scanf("%d", &stone[i][j]);
    }
  }
  for (j = 0; j < col; ++j) {
    state[row - 1][j] = stone[row - 1][j];
  }
  for (i = row - 2; i >= 0; --i) {
    for (j = 0; j < col; ++j) {
      if (j == 0 && j == col - 1) {
        state[i][j] = stone[i][j] + state[i + 1][j];

      } else if (j == 0) {
        state[i][j] = stone[i][j] + max_2(state[i + 1][j + 1], state[i + 1][j]);

      } else if (j == col - 1) {
        state[i][j] = stone[i][j] + max_2(state[i + 1][j - 1], state[i + 1][j]);

      } else {
        state[i][j] = stone[i][j] + max_3(state[i + 1][j - 1],
                                          state[i + 1][j],
                                          state[i + 1][j + 1]);
      }
    }
  }
  for (j = 1, k = 0; j < col; ++j) {
    if (state[0][k] < state[0][j]) {
      k = j;
    }
  }
  printf("%d\n", state[0][k]);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
