#include <stdio.h>

int binary_search(int * array, int size, int target) {
  int upper = size - 1;
  int lower = 0;
  int inter;
  while (lower < upper) {
    inter = (lower + upper + 1) / 2;
    if (array[inter] >= target) {
      upper = inter - 1;

    } else {
      lower = inter;
    }
  }
  return upper;
}

#define COUNT_SIZE 4500
int count[COUNT_SIZE];
int main(int argc, char * argv[]) {
  int i, j;
  int t;
  int n;
  for (i = 0; i < COUNT_SIZE; ++i) {
    count[i] = (i * i + i) / 2;
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    i = binary_search(count, COUNT_SIZE, n);
    j = n - count[i];
    if (i % 2 == 0) {
      printf("TERM %d IS %d/%d\n", n, i + 2 - j, j);
    } else {
      printf("TERM %d IS %d/%d\n", n, j, i + 2 - j);
    }
  }
  return 0;
}
