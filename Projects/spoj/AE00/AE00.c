#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[]) {
  int n, m;
  int i, j;
  scanf("%d", &n);
  m = sqrt(n);
  for (i = 1, j = 0; i <= m; ++i) {
    j += n / i - (i - 1);
  }
  printf("%d\n", j);
  return 0;
}
