#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 50
#define MAX_COL 50
int model[MAX_ROW + 1][MAX_COL + 1];

int row_delta[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int col_delta[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int state[MAX_ROW + 1][MAX_COL + 1];

int dfs(int row_count, int col_count, int row, int col) {
  if (state[row][col] != -1) {
    return state[row][col];
  }
  int i, j, k;
  int new_row, new_col;
  for (i = 0, j = 0; i < 8; ++i) {
    new_row = row + row_delta[i];
    new_col = col + col_delta[i];
    if (new_row <= 0 || new_row > row_count || new_col <= 0 || new_col > col_count) {
      continue;
    }
    if (model[new_row][new_col] - model[row][col] != 1) {
      continue;
    }
    k = dfs(row_count, col_count, new_row, new_col);
    if (j == 0 || j < k + 1) {
      j = k + 1;
    }
  }
  state[row][col] = j;
  return j;
}

int main(int argc, char * argv[]) {
  int row_count;
  int col_count;
  int i, j, k;
  int case_index = 0;
  char buffer[MAX_COL + 1];
  char c;
  while (scanf("%d%d", &row_count, &col_count), (row_count > 0 && col_count > 0)) {
    case_index++;
    for (i = 1; i <= row_count; ++i) {
      scanf("%s", buffer);
      for (j = 1; j <= col_count; ++j) {
        model[i][j] = (buffer[j - 1] - 'A');
        state[i][j] = -1;
      }
    }
    k = -1;
    for (i = 1; i <= row_count; ++i) {
      for (j = 1; j <= col_count; ++j) {
        if (model[i][j] != 0) {
          continue;
        }
        dfs(row_count, col_count, i, j);
        if (k == -1 || k < state[i][j]) {
          k = state[i][j];
        }
      }
    }
    printf("Case %d: %d\n", case_index, (k + 1));
  }
  return 0;
}
