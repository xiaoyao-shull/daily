#include <stdio.h>
#include <stdlib.h>

int count_zeros(int base) {
  if (base < 5) {
    return 0;
  }
  return base / 5 + count_zeros(base / 5);
}

int main(int argc, char * argv[]) {
  int case_count;
  int base;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &base);
    printf("%d\n", count_zeros(base));
  }
  return 0;
}
