#include <stdio.h>

int binary_search(long long * array, int size, long long target) {
  int lower = 0;
  int upper = size - 1;
  int inter;
  while (lower < upper) {
    inter = (lower + upper) / 2;
    if (array[inter] < target) {
      lower = inter + 1;

    } else {
      upper = inter;
    }
  }
  return array[lower] == target ? lower : -1;
}

int main(int argc, char * argv[]) {
  long long squares[1000001];
  long long u, v, w;
  int i;
  int case_count;
  for (i = 0; i <= 1000000; ++i) {
    squares[i] = (long long) i * (long long) i;
  }
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%lld", &u);
    for (v = 0LL, i = 0; v * v <= u / 2LL; ++v) {
      if (binary_search(squares, 1000001, u - v * v) != -1) {
        i = 1;
        break;
      }
    }
    printf("%s\n", i == 1 ? "Yes" : "No");
  }
  return 0;
}
