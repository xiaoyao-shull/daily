#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task_t {
  int start;
  int end;
};
typedef struct task_t task_t;

#define T task_t
int quick_sort_partition(T * array, int lower, int upper, int (*less)(T x, T y)) {
  T pivot = array[(lower + upper) / 2];
  T temp;
  lower--;
  upper++;
  while (1) {
    do { lower++; } while (less(array[lower], pivot));
    do { upper--; } while (less(pivot, array[upper]));
    if (lower >= upper) {
      return upper;
    }
    temp = array[lower];
    array[lower] = array[upper];
    array[upper] = temp;
  }
}

void quick_sort(T * array, int lower, int upper, int (*less)(T x, T y)) {
  if (lower >= upper) {
    return;
  }
  int inter = quick_sort_partition(array, lower, upper, less);
  quick_sort(array, lower, inter, less);
  quick_sort(array, inter + 1, upper, less);
}
#undef T

#define MAX_TASK_COUNT 100000

int task_less(task_t x, task_t y) {
  return x.end < y.end;
}

int main(int argc, char * argv[]) {
  int i, j, k;
  int case_count;
  int task_count;
  task_t tasks[MAX_TASK_COUNT];
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &task_count);
    for (i = 0; i < task_count; ++i) {
      scanf("%d%d", &tasks[i].start, &tasks[i].end);
    }
    quick_sort(tasks, 0, task_count - 1, task_less);
    for (i = 0, j = 0, k = 0; i < task_count; ++i) {
      if (tasks[i].start >= j) {
        k++;
        j = tasks[i].end;
      }
    }
    printf("%d\n", k);
  }
  return 0;
}
