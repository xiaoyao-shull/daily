#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2500

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
int sum1[MAX_SIZE * MAX_SIZE];
int sum2[MAX_SIZE * MAX_SIZE];

int main(int argc, char * argv[]) {
  int size;
  int i, j;
  int p, q;
  int n1, n2, n3, n4, ns;
  long long r;
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  }
  ns = 0;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      sum1[ns] = a[i] + b[j];
      sum2[ns] = c[i] + d[j];
      ns++;
    }
  }
  quick_sort(sum1, 0, ns - 1);
  quick_sort(sum2, 0, ns - 1);
  i = 0;
  j = ns - 1;
  r = 0;
  while (i < ns && j >= 0) {
    if (sum1[i] + sum2[j] > 0) {
      j--;
      continue;
    }
    if (sum1[i] + sum2[j] < 0) {
      i++;
      continue;
    }
    for (p = i; p + 1 < ns && sum1[p + 1] == sum1[p]; ++p);
    for (q = j; q - 1 >= 0 && sum2[q - 1] == sum2[q]; --q);
    r += (p - i + 1) * (j - q + 1);
    i = p + 1;
    j = q - 1;
  }
  printf("%lld\n", r);
  return 0;
}
