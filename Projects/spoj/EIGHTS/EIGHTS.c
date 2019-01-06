#include <stdio.h>

int main(int argc, char * argv[]) {
  int case_count;
  long long k;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%lld", &k);
    printf("%lld\n", (k - 1LL) * 250LL + 192LL);
  }
  return 0;
}
