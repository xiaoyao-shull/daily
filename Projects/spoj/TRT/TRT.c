#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2000

int size;
int array[MAX_SIZE];
int state[MAX_SIZE * MAX_SIZE];

long dp(int * array, int size, int start, int end) {
  if (start > end) {
    return 0L;
  }
  if (state[start * MAX_SIZE + end] != 0) {
    return state[start * MAX_SIZE + end];
  }
  long age = (start - 0L) + ((size - 1L) - end) + 1L;
  long m = age * array[start] + dp(array, size, start + 1, end);
  long n = age * array[end] + dp(array, size, start, end - 1);
  if (m > n) {
    state[start * MAX_SIZE + end] = m;
    return m;

  } else {
    state[start * MAX_SIZE + end] = n;
    return n;
  }
}

int main(int argc, char * argv[]) {
  int i;
  memset(array, 0, sizeof(array));
  memset(state, 0, sizeof(state));
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d", &array[i]);
  }
  printf("%ld\n", dp(array, size, 0, size - 1));
  return 0;
}
