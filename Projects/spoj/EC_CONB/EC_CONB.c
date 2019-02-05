#include <stdio.h>
#include <string.h>

void run() {
  int n;
  int i, j, k;
  int b[31];
  scanf("%d", &n);
  if (n % 2 == 1) {
    printf("%d\n", n);
    return;
  }
  memset(b, 0, sizeof(b));
  for (i = 0, j = 1; i < 30; ++i, j <<= 1) {
    b[i] = (n & j) > 0;
  }
  for (i = 30; i >= 0 && !b[i]; --i) {

  }
  for (j = 1, k = 0; i >= 0; --i, j <<= 1) {
    k += j * b[i];
  }
  printf("%d\n", k);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
