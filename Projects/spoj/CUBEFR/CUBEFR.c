#include <stdio.h>

#define MAX_SIZE 1000000

int main(int argc, char * argv[]) {
  int flag[MAX_SIZE + 1] = { 0 };
  int order[MAX_SIZE + 1];
  int i, j, k;
  int case_count, case_index;
  for (i = 2, j = i * i * i; j <= MAX_SIZE; ++i, j = i * i * i) {
    flag[j] = 1;
    for (k = 2 * j; k <= MAX_SIZE; k += j) {
      flag[k] = 1;
    }
  }
  for (i = 1, j = 0; i <= MAX_SIZE; ++i) {
    if (flag[i] == 0) {
      order[i] = ++j;

    } else {
      order[i] = -1;
    }
  }

  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    scanf("%d", &i);
    if (order[i] == -1) {
      printf("Case %d: Not Cube Free\n", case_index);

    } else {
      printf("Case %d: %d\n", case_index, order[i]);
    }
  }
  return 0;
}
