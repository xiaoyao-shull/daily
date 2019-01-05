#include <stdio.h>

#define MAX_LABEL 1000000000
long long buffer[MAX_LABEL + 1] = { 0 };

long long dp(int label) {
  long long i, j, k;
  long long v;
  if (label == 0) {
    return 0;
  }
  if (label == 1 || label == 2) {
    return label;
  }
  if (buffer[label] > 0) {
    return buffer[label];
  }
  i = label / 2LL;
  j = label / 3LL;
  k = label / 4LL;
  v = dp(i) + dp(j) + dp(k);
  if (v < label) {
    v = label;
  }
  buffer[label] = v;
  return v;
}

int main(int argc, char * argv[]) {
  int label;
  while (scanf("%d", &label) > 0) {
    printf("%lld\n", dp(label));
  }
  return 0;
}
