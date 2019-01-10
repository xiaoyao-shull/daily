#include <stdio.h>

int main(int argc, char * argv[]) {
  int i;
  int n;
  int x;
  int y = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    y = x ^ y;
  }
  printf("%d\n", y);
  return 0;
}
