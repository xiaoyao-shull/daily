#include <stdio.h>

#define MAX_SIZE 20000

int binary_search(int * array, int size, int target) {
  int lower = 1;
  int upper = size - 1;
  int inter;
  while (lower < upper) {
    inter = (lower + upper) / 2;
    if (array[inter] >= target) {
      upper = inter;
    } else {
      lower = inter + 1;
    }
  }
  return array[lower] == target;
}

int main(int argc, char * argv[]) {
  int array[MAX_SIZE + 1];
  int i;
  for (i = 1; i <= MAX_SIZE; ++i) {
    array[i] = 3 * i * i - 3 * i + 1;
  }
  while (scanf("%d", &i), i != -1) {
    printf("%s\n", binary_search(array, MAX_SIZE, i) ? "Y" : "N");
  }
  return 0;
}
