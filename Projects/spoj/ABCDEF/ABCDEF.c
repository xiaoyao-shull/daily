#include <stdio.h>

int quicksort_partition(int * array, int lower, int upper) {
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

void quicksort(int * array, int lower, int upper) {
  if (lower >= upper) {
    return;
  }
  int inter = quicksort_partition(array, lower, upper);
  quicksort(array, lower, inter);
  quicksort(array, inter + 1, upper);
}

int binary_search_leftmost(int * array, int size, int target) {
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
  return array[lower] == target ? lower : -1;
}

int binary_search_rightmost(int * array, int size, int target) {
  int lower = 0;
  int upper = size - 1;
  int inter;
  while (lower < upper) {
    inter = (lower + upper + 1) / 2;
    if (array[inter] > target) {
      upper = inter - 1;
    } else {
      lower = inter;
    }
  }
  return array[upper] == target ? upper : -1;
}

int binary_count(int * array, int size, int target) {
  int leftmost;
  int rightmost;
  leftmost = binary_search_leftmost(array, size, target);
  if (leftmost == -1) {
    return 0;
  }
  rightmost = binary_search_rightmost(array, size, target);
  return rightmost - leftmost + 1;
}

#define MAX_NUMBER_COUNT 100
#define MAX_RESULT_COUNT (MAX_NUMBER_COUNT * MAX_NUMBER_COUNT * MAX_NUMBER_COUNT)
int main(int argc, char * argv[]) {
  int number_count = 0;
  int result_count = 0;
  int equals_count = 0;
  int results[MAX_RESULT_COUNT];
  int numbers[MAX_NUMBER_COUNT];
  int i, j, k;
  int u, v, w;
  scanf("%d", &number_count);
  for (i = 0; i < number_count; ++i) {
    scanf("%d", &numbers[i]);
  }
  for (i = 0; i < number_count; ++i) {
    for (j = 0; j < number_count; ++j) {
      for (k = 0; k < number_count; ++k) {
        u = numbers[i];
        v = numbers[j];
        w = numbers[k];
        results[result_count] = u * v + w;
        result_count++;
      }
    }
  }
  quicksort(results, 0, result_count - 1);
  for (i = 0; i < number_count; ++i) {
    for (j = 0; j < number_count; ++j) {
      for (k = 0; k < number_count; ++k) {
        u = numbers[i];
        v = numbers[j];
        w = numbers[k];
        if (w == 0) {
          continue;
        }
        equals_count += binary_count(results, result_count, w * (u + v));
      }
    }
  }
  printf("%d\n", equals_count);
  return 0;
}
