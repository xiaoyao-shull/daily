#include <stdio.h>
#include <stdlib.h>

long long choose(int n, int r) {
  if(r > n - r) {
    r = n - r;
  }
  int i;
  long long j;
  for(i = 1, j = 1; i <= r; i++) {
    j *= n - r + i;
    j /= i;
  }
  return j;
}

int main(int argc, char * argv[]) {
  int case_count;
  int i, j;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &i, &j);
    printf("%lld\n", choose(i - 1, j - 1));
  }
  return 0;
}
