#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 1000000

int get_majority(int * array, int size) {
  int i, j, k;
  for (i = 1, j = 0, k = 1; i < size; ++i) {
    if (array[i] == array[j]) {
      k++;
    } else {
      k--;
    }
    if (k == 0) {
      j = i;
      k = 1;
    }
  }
  for (i = 0, k = 0; i < size; ++i) {
    if (array[i] == array[j]) {
      k++;
    }
  }
  return k > size / 2 ? array[j] : INT_MIN;
}

int main(int argc, char * argv[]) {
  int i;
  int case_count;
  int size;
  int array[MAX_SIZE];
  scanf("%d'", &case_count);
  while (case_count--) {
    scanf("%d", &size);
    for (i = 0; i < size; ++i) {
      scanf("%d", &array[i]);
    }
    i = get_majority(array, size);
    if (i == INT_MIN) {
      printf("NO\n");

    } else {
      printf("YES %d\n", i);
    }
  }
  return 0;
}
