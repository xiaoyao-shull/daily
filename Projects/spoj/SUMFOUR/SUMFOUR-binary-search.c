#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2500

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

int a[MAX_SIZE];
int b[MAX_SIZE];
int c[MAX_SIZE];
int d[MAX_SIZE];
int sum[MAX_SIZE * MAX_SIZE];

int main(int argc, char * argv[]) {
  int size;
  int i, j, k;
  int n1, n2, n3, n4, ns;
  int p, q;
  long long r;
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  }

  ns = 0;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      sum[ns++] = a[i] + b[j];
    }
  }
  quick_sort(sum, 0, ns - 1);

  r = 0;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      k = -(c[i] + d[j]);
      p = binary_search_leftmost(sum, ns, k);
      if (p == -1) {
        continue;
      }
      q = binary_search_rightmost(sum, ns, k);
      r += (q - p + 1);
    }
  }
  printf("%lld\n", r);
  return 0;
}
