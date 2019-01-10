#include <stdio.h>

int main(int argc, char * argv[]) {
  int n;
  int a, b;
  scanf("%d", &n);
  a = n / 10;
  b = n % 10;
  if (b == 0) {
    printf("2\n");

  } else {
    printf("%d\n%d\n", 1, b);
  }
  return 0;
}
