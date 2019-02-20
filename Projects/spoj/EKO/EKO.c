#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_COUNT 1000000
#define MAX_WOOD_COUNT 2000000000LL
#define MAX_HEIGHT 1000000000LL

long long height[MAX_TREE_COUNT];

int compare_long(const void * lhs, const void * rhs) {
  long long diff = *((const long long *) lhs) - *((const long long *) rhs);
  if (diff > 0) {
    return 1;
  }
  if (diff < 0) {
    return -1;
  }
  return 0;
}

long long max(long long x, long long y) {
  return x > y ? x : y;
}

int main(int argc, char * argv[]) {
  int tree_count;
  long long wood_count;
  int i;
  long long lower, upper, inter;
  long long wood;
  scanf("%d%lld", &tree_count, &wood_count);
  for (i = 0; i < tree_count; ++i) {
    scanf("%lld", &height[i]);
  }
  qsort((void *) height, tree_count, sizeof(long long), compare_long);

  lower = 0;
  upper = MAX_HEIGHT;
  while (lower < upper) {
    inter = (lower + upper + 1LL) / 2LL;
    for (i = 0, wood = 0LL; i < tree_count; ++i) {
      wood += max(height[i] - inter, 0LL);
    }
    if (wood < wood_count) {
      upper = inter - 1;

    } else {
      lower = inter;
    }
  }
  printf("%lld\n", upper);
  return 0;
}
