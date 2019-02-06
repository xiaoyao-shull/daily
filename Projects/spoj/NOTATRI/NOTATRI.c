#include <stdio.h>

int sort_partition(int * array, int lower, int upper) {
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

void sort(int * array, int lower, int upper) {
  if (lower >= upper) {
    return;
  }
  int inter = sort_partition(array, lower, upper);
  sort(array, lower, inter);
  sort(array, inter + 1, upper);
}

int binary_search(int * array, int size, int target) {
  int lower = 0;
  int upper = size - 1;
  int inter;
  while (lower < upper) {
    inter = (lower + upper) / 2;
    if (array[inter] < target) {
      lower = inter + 1;

    } else {
      upper = inter;
    }
  }
  return array[lower] >= target ? lower : -1;
}

#define MAX_SIZE 2000

int main(int argc, char * argv[]) {
  int size;
  int array[MAX_SIZE];
  int i, j, k;
  int u;
  while (scanf("%d", &size), size > 0) {
    for (i = 0; i < size; ++i) {
      scanf("%d", &array[i]);
    }
    sort(array, 0, size - 1);
    for (i = 0, k = 0; i < size; ++i) {
      for (j = i + 1; j < size; ++j) {
        u = binary_search(array, size, array[i] + array[j] + 1);
        if (u != -1) {
          k += size - u;

        } else {
          break;
        }
      }
      if (j == i + 1) {
        break;
      }
    }
    printf("%d\n", k);
  }
  return 0;
}
