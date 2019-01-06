#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200000
int array[MAX_SIZE];
int buffer[MAX_SIZE];

long long merge_sort(int * array, int start, int end) {
  if (end - start <= 1) {
    return 0LL;
  }
  int middle = (start + end) / 2;
  int i, j, k;
  long long invert;

  invert = 0LL;
  invert += merge_sort(array, start, middle);
  invert += merge_sort(array, middle, end);

  i = start;
  j = start;
  k = middle;
  while (j < middle || k < end) {
    if (j >= middle) {
      buffer[i++] = array[k++];
      continue;
    }
    if (k >= end) {
      buffer[i++] = array[j++];
      continue;
    }
    if (array[j] <= array[k]) {
      buffer[i++] = array[j++];

    } else {
      invert += (middle - j);
      buffer[i++] = array[k++];
    }
  }
  memcpy(&array[start], &buffer[start], sizeof(int) * (end - start));
  return invert;
}

void run() {
  int size;
  int i;
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d", &array[i]);
  }
  printf("%lld\n", merge_sort(array, 0, size));
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
