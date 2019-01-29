#include <stdio.h>
#include <string.h>

#define SIZE 2700
int factor_count[SIZE + 1];
int lucky[SIZE + 1];
int lucky_count = 0;

void init() {
  int i, j;
  memset(factor_count, 0, sizeof(factor_count));
  for (i = 2; i <= SIZE; ++i) {
    if (factor_count[i] >= 3) {
      lucky[lucky_count] = i;
      lucky_count++;
    }
    if (factor_count[i] == 0) {
      for (j = i * 2; j <= SIZE; j += i) {
        factor_count[j]++;
      }
    }
  }
}

int main(int argc, char * argv[]) {
  int t, n;
  init();
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", lucky[n - 1]);
  }
  return 0;
}
