#include <stdio.h>

int main(long long argc, char * argv[]) {
  long long case_count;
  long long child_count;
  long long candy_count;
  long long i, j;
  scanf("%lld", &case_count);
  while (case_count--) {
    scanf("%lld", &child_count);
    for (i = 0LL, candy_count = 0LL; i < child_count; ++i) {
      scanf("%lld", &j);
      candy_count += (j % child_count);
      candy_count %= child_count;
    }
    printf("%s\n", candy_count == 0 ? "YES" : "NO");
  }
  return 0;
}
