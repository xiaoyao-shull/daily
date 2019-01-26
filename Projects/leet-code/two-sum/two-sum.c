#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
struct number_t {
  int index;
  int value;
};
typedef struct number_t number_t;

int number_less(number_t x, number_t y) {
  return x.value < y.value;
}

int quick_sort_partition(number_t * numbers, int lower, int upper) {
  number_t pivot = numbers[(lower + upper) / 2];
  int i = lower - 1;
  int j = upper + 1;
  number_t temp;
  while (1) {
    do { i++; } while (number_less(numbers[i], pivot));
    do { j--; } while (number_less(pivot, numbers[j]));
    if (i >= j) {
      return j;
    }
    temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }
}

void quick_sort(number_t * numbers, int lower, int upper) {
  if (lower >= upper) {
    return;
  }
  int inter = quick_sort_partition(numbers, lower, upper);
  quick_sort(numbers, lower, inter);
  quick_sort(numbers, inter + 1, upper);
}

int * solve(int * array, int size, int target) {
  number_t * numbers = malloc(sizeof(number_t) * size);
  int i, j;
  int * result;
  for (i = 0; i < size; ++i) {
    numbers[i].index = i;
    numbers[i].value = array[i];
  }
  quick_sort(numbers, 0, size - 1);

  i = 0;
  j = size - 1;
  while (1) {
    if (numbers[i].value + numbers[j].value < target) {
      i++;

    } else if (numbers[i].value + numbers[j].value > target) {
      j--;

    } else {
      break;
    }
  }
  result = malloc(sizeof(int) * 2);
  result[0] = numbers[i].index;
  result[1] = numbers[j].index;
  free(numbers);
  return result;
}

int* twoSum(int* nums, int numsSize, int target) {
  return solve(nums, numsSize, target);
}
// -----------------------------------------------------------------------------

void test(int * array, int size, int target) {
  int * result = twoSum(array, size, target);
  int i = result[0];
  int j = result[1];
  int sum = array[i] + array[j];
  free(result);
  printf("%s\n", sum == target ? "passed" : "failed");
}

int main(int argc, char * argv[]) {
  int array[10];
  array[0] = 3;
  array[1] = 2;
  array[2] = 4;
  test(array, 3, 6);
  return 0;
}
