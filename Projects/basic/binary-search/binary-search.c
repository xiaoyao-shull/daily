#include <stdio.h>

int search_leftmost(int * array, int target, int size) {
  int lower = 0;
  int upper = size - 1;
  int inter;
  while (lower < upper) {
    inter = (lower + upper) / 2; // inter might equals lower
    if (array[inter] < target) {
      lower = inter + 1; // update lower with strict condition, avoid infinite loop as well

    } else {
      upper = inter;
    }
  }
  return lower;
}

int search_rightmost(int * array, int target, int size) {
  int lower = 0;
  int upper = size - 1;
  int inter;
  while (lower < upper) {
    inter = (lower + upper + 1) / 2; // inter might equals upper
    if (array[inter] > target) {
      upper = inter - 1; // update upper with strict condition, avoid infinite loop as well
    } else {
      lower = inter;
    }
  }
  return upper;
}

int main(int argc, char * argv[]) {
  int array_size = 9;
  int array[] = { 1, 2, 3, 4, 4, 4, 5, 6, 7 };
  int i;

  printf("array = [ ");
  for (i = 0; i < array_size; ++i) {
    printf("%d ", array[i]);
  }
  printf("]\n");

  printf("index = [ ");
  for (i = 0; i < array_size; ++i) {
    printf("%d ", i);
  }
  printf("]\n");

  printf("binary-search-leftmost returns index = %d\n", search_leftmost(array, 4, array_size));
  printf("binary-search-rightmost returns index = %d\n", search_rightmost(array, 4, array_size));
  return 0;
}
