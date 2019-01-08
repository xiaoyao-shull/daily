#include <stdio.h>

int main(int argc, char * argv[]) {
  int m;
  long long n;
  scanf("%d", &m);
  while (m--) {
    scanf("%lld", &n);
    printf("%lld\n", n * (n + 2LL) * (2LL * n + 1LL) / 8LL);
  }
  return 0;
}
