#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

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
  int size1;
  int size2;
  int array1[MAX_SIZE];
  int array2[MAX_SIZE];
  int i, j, k;
  int current_array;
  int current_value;
  int previous_array;
  int previous_value;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &size1);
    for (i = 0; i < size1; ++i) {
      scanf("%d", &array1[i]);
    }
    scanf("%d", &size2);
    for (i = 0; i < size2; ++i) {
      scanf("%d", &array2[i]);
    }
    quick_sort(array1, 0, size1 - 1);
    quick_sort(array2, 0, size2 - 1);

    i = 0;
    j = 0;
    k = INT_MAX;
    while (i < size1 || j < size2) {
      if (i >= size1) {
        current_value = array2[j++];
        current_array = 2;

      } else if (j >= size2) {
        current_value = array1[i++];
        current_array = 1;

      } else if (array1[i] < array2[j]) {
        current_value = array1[i++];
        current_array = 1;

      } else {
        current_value = array2[j++];
        current_array = 2;
      }

      if (i + j > 1 && current_array != previous_array) {
        if (k > current_value - previous_value) {
          k = current_value - previous_value;
        }
      }
      previous_array = current_array;
      previous_value = current_value;
    }
    printf("%d\n", k);
  }
  return 0;
}
