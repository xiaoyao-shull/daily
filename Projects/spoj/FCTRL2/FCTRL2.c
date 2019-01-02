#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char factorial[101][256];

void calculate_factorial(n) {
  int i, j, k;
  int p;
  memset(factorial[n], 0, sizeof(factorial[n]));
  if (n == 0 || n == 1) {
    factorial[n][0] = '1';
    return;
  }
  calculate_factorial(n - 1);
  for (i = 0, j = strlen(factorial[n - 1]), k = 0; i < j; ++i) {
    p = (factorial[n - 1][i] - '0') * n + k;
    k = p / 10;
    factorial[n][i] = p % 10 + '0';
  }
  for (p = k % 10; k > 0; k = k / 10, p = k % 10, ++i) {
    factorial[n][i] = p + '0';
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  int base;
  int i;
  calculate_factorial(100);
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &base);
    for (i = strlen(factorial[base]) - 1; i >= 0; --i) {
      printf("%c", factorial[base][i]);
    }
    printf("\n");
  }
  return 0;
}
