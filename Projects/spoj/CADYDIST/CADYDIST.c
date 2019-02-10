#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int compare_count(const void * x, const void * y) {
  long long xx = *((long long *) x);
  long long yy = *((long long *) y);

  if (xx > yy) {
    return 1;

  } else if (xx < yy) {
    return -1;

  } else {
    return 0;
  }
}

int compare_price(const void * x, const void * y) {
  long long xx = *((long long *) x);
  long long yy = *((long long *) y);

  if (xx > yy) {
    return -1;

  } else if (xx < yy) {
    return 1;

  } else {
    return 0;
  }
}

int main(int argc, char * argv[]) {
  int size;
  long long count[MAX_SIZE];
  long long price[MAX_SIZE];
  int i;
  long long k;
  while (scanf("%d", &size), size > 0) {
    for (i = 0; i < size; ++i) {
      scanf("%lld", &count[i]);
    }
    for (i = 0; i < size; ++i) {
      scanf("%lld", &price[i]);
    }
    qsort(count, size, sizeof(long long), compare_count);
    qsort(price, size, sizeof(long long), compare_price);
    for (i = 0, k = 0LL; i < size; ++i) {
      k += count[i] * price[i];
    }
    printf("%lld\n", k);
  }
  return 0;
}
