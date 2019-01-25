#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 20000

int quick_sort_partition(int * array, int lower, int upper) {
  int pivot = array[(lower + upper) / 2];
  int i = lower - 1;
  int j = upper + 1;
  int temp;
  while (1) {
    do { i++; } while (array[i] < pivot);
    do { j--; } while (array[j] > pivot);
    if (i >= j) {
      return j;
    }
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void quick_sort(int * array, int lower, int upper) {
  if (lower >= upper) {
    return;
  }
  int inter = quick_sort_partition(array, lower, upper);
  quick_sort(array, lower, inter);
  quick_sort(array, inter + 1, upper);
}

int main(int argc, char * argv[]) {
  int case_count;
  int size;
  int gap;
  int array[MAX_SIZE];
  int i, j;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &size, &gap);
    for (i = 0; i < size; ++i) {
      scanf("%d", &array[i]);
    }
    quick_sort(array, 0, size - 1);
    for (i = 0, j = INT_MAX; i + gap - 1 < size; ++i) {
      if (j > array[i + gap - 1] - array[i]) {
        j = array[i + gap - 1] - array[i];
      }
    }
    printf("%d\n", j);
  }
  return 0;
}
