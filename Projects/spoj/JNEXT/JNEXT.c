#include <stdio.h>
#include <stdlib.h>

void swap(int * array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

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
    swap(array, i, j);
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

#define MAX_SIZE 1000000

int array[MAX_SIZE];
int max[MAX_SIZE];
int size;

int run() {
  int i, j, k;
  max[size - 1] = array[size - 1];
  for (i = size - 2; i >= 0; --i) {
    if (array[i] > max[i + 1]) {
      max[i] = array[i];

    } else {
      max[i] = max[i + 1];
    }
  }

  for (i = size - 2; i >= 0; --i) {
    if (array[i] < max[i]) {
      break;
    }
  }

  if (i < 0) {
    printf("-1\n");
    return 0;
  }

  for (j = i + 2, k = i + 1; j < size; ++j) {
    if (array[j] > array[i]) {
      if (array[k] > array[j]) {
        k = j;
      }
    }
  }
  swap(array, i, k);
  sort(array, i + 1, size - 1);
  for (i = 0; i < size; ++i) {
    printf("%d", array[i]);
  }
  printf("\n");
  return 1;
}

int main(int argc, char * argv[]) {
  int case_count;
  int i;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &size);
    for (i = 0; i < size; ++i) {
      scanf("%d", &array[i]);
    }
    run();
  }
  return 0;
}
