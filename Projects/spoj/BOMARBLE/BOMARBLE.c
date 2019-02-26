#include <stdio.h>

int main(int argc, char * argv[]) {
  int n;
  while (scanf("%d", &n), n > 0) {
    printf("%d\n", (3 * n * n + 5 * n + 2) / 2);
  }
  return 0;
}
