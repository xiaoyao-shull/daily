#include <stdio.h>

void sort(int * array, int size) {
  int new_size;
  int tmp;
  int i;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (array[i - 1] > array[i]) {
        tmp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = tmp;
        new_size = i;
      }
    }
    size = new_size;
  }
}

#define MAX_SIZE 100

int main(int argc, char * argv[]) {
  int size_a, size_d, i;
  int distance_a[MAX_SIZE + 1];
  int distance_d[MAX_SIZE + 1];
  while (scanf("%d%d", &size_a, &size_d), size_a > 0 && size_d > 0) {
    for (i = 0; i < size_a; ++i) {
      scanf("%d", &distance_a[i]);
    }
    for (i = 0; i < size_d; ++i) {
      scanf("%d", &distance_d[i]);
    }
    sort(distance_a, size_a);
    sort(distance_d, size_d);
    if (size_d < 2) {
      printf("N\n");

    } else {
      printf("%s\n", distance_a[0] < distance_d[1] ? "Y" : "N");
    }
  }
  return 0;
}
