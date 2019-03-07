#include <stdio.h>

int gcd(int a, int b) {
  int t;
  while (a > 0) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}

int abs(int a) {
  return a > 0 ? a : -a;
}

int main(int argc, char * argv[]) {
  int case_count;
  int a;
  int b;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &a, &b);
    printf("%d\n", abs(a - b) / gcd(abs(a), abs(b)));
  }
  return 0;
}
