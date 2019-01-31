#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW_COUNT 1000
#define MAX_COL_COUNT 1000

struct rope_t {
  int row;
  int col;
  int len;
};
typedef struct rope_t rope_t;

char lab[MAX_ROW_COUNT][MAX_COL_COUNT + 1];
int col_count, row_count;
int row_delta[4] = { -1, 0, 1, 0 };
int col_delta[4] = { 0, 1, 0, -1 };

rope_t dfs(int row_from, int col_from, int row_to, int col_to) {
  int row_new, col_new;
  int i;
  rope_t rope_longest;
  rope_t rope;
  rope_longest.row = row_to;
  rope_longest.col = col_to;
  rope_longest.len = 0;
  for (i = 0; i < 4; ++i) {
    row_new = row_to + row_delta[i];
    col_new = col_to + col_delta[i];
    if (row_new == row_from && col_new == col_from) {
      continue;
    }
    if (row_new < 0 || row_new >= row_count) {
      continue;
    }
    if (col_new < 0 || col_new >= col_count) {
      continue;
    }
    if (lab[row_new][col_new] == '#') {
      continue;
    }
    rope = dfs(row_to, col_to, row_new, col_new);
    if (rope_longest.len < rope.len + 1) {
      rope_longest = rope;
      rope_longest.len++;
    }
  }
  return rope_longest;
}

void run() {
  int row, col;
  rope_t end;
  scanf("%d%d", &col_count, &row_count);
  for (row = 0; row < row_count; ++row) {
    scanf("%s", lab[row]);
  }
  for (row = 0; row < row_count; row++) {
    for (col = 0; col < col_count; col++) {
      if (lab[row][col] == '.') {
        break;
      }
    }
    if (col < col_count) {
      break;
    }
  }
  end = dfs(-10, -10, row, col);
  end = dfs(-10, -10, end.row, end.col);
  printf("Maximum rope length is %d.\n", end.len);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
