#include <stdio.h>

int main(int argc, char * argv[]) {
  int t, n, i, j;
  long long num;
  long long sum;
  long long min_sum;

  scanf("%d", &t);
  for (j = 1; j <= t; ++j) {
    sum = 0LL;
    min_sum = 10000001LL;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      scanf("%lld", &num);
      sum += num;
      if (min_sum > sum) {
        min_sum = sum;
      }
    }
    printf("Scenario #%d: %lld\n", j, min_sum > 0LL ? 1LL : 1LL - min_sum);
  }
  return 0;
}
