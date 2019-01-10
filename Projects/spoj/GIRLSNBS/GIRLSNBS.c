#include <stdio.h>

int main(int argc, char * argv[]) {
  int g, b;
  int m, n;
  int q, r;
  while (scanf("%d%d", &g, &b), !(g == -1 && b == -1)) {
    if (g > b) {
      m = g;
      n = b;
    } else {
      m = b;
      n = g;
    }
    q = m / (n + 1);
    r = m % (n + 1);
    printf("%d\n", r == 0 ? q : (q + 1));
  }
  return 0;
}
