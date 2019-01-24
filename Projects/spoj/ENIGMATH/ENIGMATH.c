#include <stdio.h>

int gcd(int a, int b) {
  int temp;
  while (b > 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main(int argc, char * argv[]) {
  int case_count;
  int a, b;
  int d;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &a, &b);
    d = gcd(a, b);
    printf("%d %d\n", b / d, a / d);
  }
  return 0;
}
