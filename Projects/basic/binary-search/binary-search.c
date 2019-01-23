#include <stdio.h>

int binary_search_leftmost(int * array, int size, int target) {
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

int binary_search_rightmost(int * array, int size, int target) {
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

int binary_search_index_max(int * array, int size, int target) {
  int i = binary_search_rightmost(array, size, target);
  return array[i] == target ? i : -1;
}

int binary_search_index_min(int * array, int size, int target) {
  int i = binary_search_leftmost(array, size, target);
  return array[i] == target ? i : -1;
}

int binary_search_range_ge(int * array, int size, int target) {
  int i = binary_search_leftmost(array, size, target);
  return array[i] >= target ? i : -1;
}

int binary_search_range_le(int * array, int size, int target) {
  int i = binary_search_rightmost(array, size, target);
  return array[i] <= target ? i : -1;
}

void demo(int * array, int size, int target) {
  printf("index_max(%2d) = %2d, index_min(%2d) = %2d, range_ge(%2d) = %2d, range_le(%2d) = %2d\n",
         target, binary_search_index_max(array, size, target),
         target, binary_search_index_min(array, size, target),
         target, binary_search_range_ge(array, size, target),
         target, binary_search_range_le(array, size, target));
}

int main(int argc, char * argv[]) {
  int array_size = 9;
  int array[] = { 1, 2, 3, 5, 5, 5, 7, 8, 9 };
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

  demo(array, array_size, 5);
  demo(array, array_size, 4);
  demo(array, array_size, 6);
  demo(array, array_size, -1);
  demo(array, array_size, 10);

  return 0;
}
