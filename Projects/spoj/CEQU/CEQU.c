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

// equation ax + by = c has integer solutions if and only if gcd(a, b) | c.
int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  int a, b, c;
  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    scanf("%d%d%d", &a, &b, &c);
    printf("Case %d: %s\n", case_index, c % gcd(a, b) == 0 ? "Yes" : "No");
  }
  return 0;
}
