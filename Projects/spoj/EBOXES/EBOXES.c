#include <stdio.h>

int main(int argc, char * argv[]) {
  int case_count;
  int n, k, t, f;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d%d%d", &n, &k, &t, &f);
    printf("%d\n", (f - n) / (k - 1) + f);
  }
  return 0;
}
