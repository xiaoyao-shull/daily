#include <stdio.h>

int sort_partition(int * array, int lower, int upper) {
  int i = lower - 1;
  int j = upper + 1;
  int pivot = array[(lower + upper) / 2];
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

#define MAX_SIZE 100

int main(int argc, char * argv[]) {
  int join_times[MAX_SIZE];
  int quit_times[MAX_SIZE];
  int i, j, k;
  int max;
  int size;
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &size);
    for (i = 0; i < size; ++i) {
      scanf("%d%d", &join_times[i], &quit_times[i]);
    }
    sort(join_times, 0, size - 1);
    sort(quit_times, 0, size - 1);
    i = 0;
    j = 0;
    k = 0;
    max = 0;
    while (i < size || j < size) {
      if (i >= size) {
        break;
      }
      if (j >= size || join_times[i] < quit_times[j]) {
        k++;
        i++;

      } else if (join_times[i] > quit_times[j]) {
        k--;
        j++;

      } else {
        i++;
        j++;
      }
      if (max < k) {
        max = k;
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
