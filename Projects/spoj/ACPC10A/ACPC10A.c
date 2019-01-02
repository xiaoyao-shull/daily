#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  int i, j, k;
  while (1) {
    scanf("%d%d%d", &i, &j, &k);
    if (i == 0 && j == 0 && k == 0) {
      break;
    }
    if (j - i == k - j) {
      printf("AP %d\n", k + (k - j));

    } else if (i != 0 &&
               j != 0 &&
               k != 0 &&
               j % i == 0 &&
               k % j == 0 &&
               j / i == k / j) {

      printf("GP %d\n", k * (k / j));
    }
  }
  return 0;
}
