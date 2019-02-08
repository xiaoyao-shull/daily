#include <stdio.h>

int main(int argc, char * argv[]) {
  int case_count;
  int row;
  int col;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &row, &col);
    if (row > col) {
      printf("%s\n", col % 2 == 1 ? "D" : "U");
    } else {
      printf("%s\n", row % 2 == 1 ? "R" : "L");
    }
  }
  return 0;
}
