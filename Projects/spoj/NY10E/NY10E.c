#include <stdio.h>

#define MAX_SIZE 64

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  int n, i, j;
  long long k;
  long long state[MAX_SIZE][10];
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &case_index, &n);
    for (i = n - 1, j = 9; j >= 0; --j) {
      state[n - 1][j] = 10 - j;
    }
    for (i = n - 2; i >= 0; --i) {
      for (j = 9, k = 0LL; j >= 0; --j) {
        k += state[i + 1][j];
        state[i][j] = k;
      }
    }
    printf("%d %lld\n", case_index, state[0][0]);
  }
  return 0;
}
