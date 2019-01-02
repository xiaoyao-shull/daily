#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  int case_count;
  int x, y;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &x, &y);
    if (y == x || y == x - 2) {
      if (y % 2 == 0) {
        printf("%d\n", x + y);

      } else {
        printf("%d\n", x + y - 1);
      }

    } else {
      printf("No Number\n");
    }
  }
  return 0;
}
