#include <stdio.h>

int main(int argc, char * argv[]) {
  int n;
  int i;
  while (scanf("%d", &n), n > 0) {
    while (n != (n & (-n))) {
      n -= (n & (-n));
    }
    i = 0;
    while (n > 1) {
      n >>= 1;
      i++;
    }
    printf("%d\n", i);
  }
  return 0;
}
