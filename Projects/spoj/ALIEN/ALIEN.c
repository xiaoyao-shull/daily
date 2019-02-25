#include <stdio.h>
#define MAX_SIZE 100000

int main(int argc, char * argv[]) {
  int case_count;
  int size;
  int limit;
  int i, j, k;
  int u, v;
  int values[MAX_SIZE];
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &size, &limit);
    for (i = 0; i < size; ++i) {
      scanf("%d", &values[i]);
    }
    for (i = 0, j = 0, k = 0, u = 0, v = 0; i < size; ++i) {
      while (j < size && k + values[j] <= limit) {
        k += values[j];
        j++;
      }
      if (v < j - i || (v == (j - i) && u > k)) {
        v = j - i;
        u = k;
      }
      if (j < size) {
        k -= values[i];

      } else {
        break;
      }
    }
    printf("%d %d\n", u, v);
  }
  return 0;
}
