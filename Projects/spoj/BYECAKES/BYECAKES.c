#include <stdio.h>

int main(int argc, char * argv[]) {
  int a, b, c, d;
  int A, B, C, D;
  int n;
  int m;
  while (1) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    scanf("%d%d%d%d", &A, &B, &C, &D);
    if (a == -1) {
      break;
    }
    n = (a + (A - 1)) / A;

    m = (b + (B - 1)) / B;
    if (n < m) {
      n = m;
    }

    m = (c + (C - 1)) / C;
    if (n < m) {
      n = m;
    }

    m = (d + (D - 1)) / D;
    if (n < m) {
      n = m;
    }
    printf("%d %d %d %d\n", A * n - a, B * n - b, C * n - c, D * n - d);
  }
  return 0;
}
