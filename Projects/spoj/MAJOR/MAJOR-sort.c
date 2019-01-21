#include <stdio.h>

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

#define MAX_SIZE 1000000

int main(int argc, char * argv[]) {
  int i, j;
  int case_count;
  int size;
  int array[MAX_SIZE];
  scanf("%d'", &case_count);
  while (case_count--) {
    scanf("%d", &size);
    for (i = 0; i < size; ++i) {
      scanf("%d", &array[i]);
    }
    quick_sort(array, 0, size - 1);
    for (i = 0, j = size / 2; j < size; ++i, ++j) {
      if (array[i] == array[j]) {
        printf("YES %d\n", array[i]);
        break;
      }
    }
    if (j >= size) {
      printf("NO\n");
    }
  }
  return 0;
}
