#include <stdio.h>

int main(int argc, char * argv[]) {
  int case_count;
  long a, b, s, n, d, j;
  int i;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%ld%ld%ld", &a, &b, &s);
    n = 2L * s / (a + b);
    d = (b - a) / (n - 5L);
    printf("%ld\n", n);
    for (i = 1, j = a - 2 * d; i <= n; ++i, j += d) {
      printf("%ld%s", j, i == n ? "\n" : " ");
    }
  }
  return 0;
}
