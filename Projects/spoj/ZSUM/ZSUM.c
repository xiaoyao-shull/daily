#include <stdio.h>
#include <stdlib.h>

#define MODULAR 10000007

long long madd(long long x, long long y) {
  return (x + y) % MODULAR;
}

long long mmul(long long x, long long y) {
  return x * y % MODULAR;
}

long long mexp(long long b, long long e) {
  long long r = 1;
  b = b % MODULAR;
  while (e > 0) {
    if (e % 2 == 1) {
      r = mmul(r, b);
    }
    e >>= 1;
    b = mmul(b, b);
  }
  return r;
}

int main(int argc, char * argv[]) {
  long long n, k;
  while (scanf("%lld%lld", &n, &k), !(n == 0 && k == 0)) {
    printf("%lld\n", madd(madd(madd(mexp(n, k), mmul(2, mexp(n - 1, k))), mexp(n, n)), mmul(2, mexp(n - 1, n - 1))));
  }
  return 0;
}
