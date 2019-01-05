#include <stdio.h>

void sort(int * array, int size) {
  int i;
  int tmp;
  int new_size = size;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (array[i - 1] < array[i]) {
        tmp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = tmp;
        new_size = i;
      }
    }
    size = new_size;
  }
}

#define MAX_SIZE 1000

int main(int argc, char * argv[]) {
  int x[MAX_SIZE];
  int y[MAX_SIZE];
  int n;
  int i, j;
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      scanf("%d", &x[i]);
    }
    for (i = 0; i < n; ++i) {
      scanf("%d", &y[i]);
    }
    sort(x, n);
    sort(y, n);
    for (i = 0, j = 0; i < n; ++i) {
      j += x[i] * y[i];
    }
    printf("%d\n", j);
  }
  return 0;
}
