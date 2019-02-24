#include <stdio.h>

#define MAX_ROW_COUNT 1000
#define MAX_COL_COUNT 1000

struct piece_t {
  int row_lower;
  int row_upper;
  int col_lower;
  int col_upper;
};
typedef struct piece_t piece_t;

int hcut_cost[MAX_ROW_COUNT - 1];
int vcut_cost[MAX_COL_COUNT - 1];
int stack_size;
piece_t stack[MAX_ROW_COUNT * MAX_COL_COUNT];

void run() {
  int i, j, k;
  int hcut;
  int cost;
  int row_count;
  int col_count;
  piece_t piece;

  scanf("%d%d", &col_count, &row_count);
  for (i = 0; i < col_count - 1; ++i) {
    scanf("%d", &vcut_cost[i]);
  }
  for (i = 0; i < row_count - 1; ++i) {
    scanf("%d", &hcut_cost[i]);
  }
  stack_size = 1;
  stack[0].row_lower = 0;
  stack[0].row_upper = row_count - 1;
  stack[0].col_lower = 0;
  stack[0].col_upper = col_count - 1;

  cost = 0;
  while (stack_size > 0) {
    piece = stack[stack_size - 1];
    stack_size--;
    if (piece.row_lower == piece.row_upper) {
      for (i = piece.col_lower; i < piece.col_upper; ++i) {
        cost += vcut_cost[i];
      }
      continue;
    }
    if (piece.col_lower == piece.col_upper) {
      for (i = piece.row_lower; i < piece.row_upper; ++i) {
        cost += hcut_cost[i];
      }
      continue;
    }

    for (i = piece.row_lower, j = -1, k = -1; i < piece.row_upper; ++i) {
      if (k < hcut_cost[i]) {
        k = hcut_cost[i];
        j = i;
        hcut = 1;
      }
    }
    for (i = piece.col_lower; i < piece.col_upper; ++i) {
      if (k < vcut_cost[i]) {
        k = vcut_cost[i];
        j = i;
        hcut = 0;
      }
    }

    cost += k;
    if (hcut == 1) {
      stack[stack_size].col_lower = piece.col_lower;
      stack[stack_size].col_upper = piece.col_upper;
      stack[stack_size].row_lower = piece.row_lower;
      stack[stack_size].row_upper = j;
      stack_size++;

      stack[stack_size].col_lower = piece.col_lower;
      stack[stack_size].col_upper = piece.col_upper;
      stack[stack_size].row_lower = j + 1;
      stack[stack_size].row_upper = piece.row_upper;
      stack_size++;

    } else {
      stack[stack_size].row_lower = piece.row_lower;
      stack[stack_size].row_upper = piece.row_upper;
      stack[stack_size].col_lower = piece.col_lower;
      stack[stack_size].col_upper = j;
      stack_size++;

      stack[stack_size].row_lower = piece.row_lower;
      stack[stack_size].row_upper = piece.row_upper;
      stack[stack_size].col_lower = j + 1;
      stack[stack_size].col_upper = piece.col_upper;
      stack_size++;
    }
  }
  printf("%d\n", cost);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
