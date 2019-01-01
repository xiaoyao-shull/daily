#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME_LIMIT 100000

int primes[10000];
int prime_count;

void init_primes() {
  int b[MAX];
  int i, j, k;
  memset(b, 0, sizeof(b));
  for (i = 2, prime_count = 0; i < MAX; ++i) {
    if (b[i] == 0) {
      primes[prime_count] = i;
      prime_count++;
      for (k = i * 2; k <= MAX; k += i) {
        b[k] = 1;
      }
    }
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  int u, v;
  int i, j;
  int b[100000];
  init_primes();
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &u, &v);
    memset(b, 0, sizeof(b));
    for (i = 0; i < prime_count && primes[i] * primes[i] <= v; ++i) {
      for (j = ((u - 1) / primes[i] + 1) * primes[i]; j <= v; j += primes[i]) {
        if (j == primes[i]) {
          continue;
        }
        b[j - u] = 1;
      }
    }
    for (i = u; i <= v; ++i) {
      if (i < 2) {
        continue;
      }
      if (b[i - u] == 0) {
        printf("%d\n", i);
      }
    }
    printf("\n");
  }
  return 0;
}
