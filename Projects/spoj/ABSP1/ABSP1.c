#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000
long long array[MAX_SIZE];

void run() {
  int n;
  int i;
  long long j, k;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%lld", &array[i]);
  }
  for (i = 0, j = 1 - n, k = 0; i < n; i += 1, j += 2) {
    k += array[i] * j;
  }
  printf("%lld\n", k);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
