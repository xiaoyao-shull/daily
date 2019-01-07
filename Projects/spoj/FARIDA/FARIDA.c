#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

long max_2(long x, long y) {
  return x > y ? x : y;
}

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  int array[MAX_SIZE + 1];
  long state[MAX_SIZE + 1];
  int size;
  int i;
  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    scanf("%d", &size);
    for (i = 1; i <= size; ++i) {
      scanf("%d", &array[i]);
    }
    state[0] = 0;
    state[1] = array[1];
    for (i = 2; i <= size; ++i) {
      state[i] = max_2(state[i - 1], state[i - 2] + array[i]);
    }
    printf("Case %d: %ld\n", case_index, state[size]);
  }
  return 0;
}
