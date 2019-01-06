#include <stdio.h>

#define MAX_SLOT 100000

void sort(int * array, int size) {
  int new_size;
  int tmp;
  int i;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (array[i - 1] > array[i]) {
        tmp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = tmp;
        new_size = i;
      }
    }
    size = new_size;
  }
}

int main(int argc, char * argv[]) {
  int item_count;
  int slot_count;
  int case_count;
  int slot[MAX_SLOT + 1];
  int lower, upper, inter;
  int i, j, k;
  scanf("%d", &case_count);
  while(case_count--) {
    scanf("%d%d", &slot_count, &item_count);
    for (i = 0; i < slot_count; ++i) {
      scanf("%d", &slot[i]);
    }
    sort(slot, slot_count);
    lower = 1;
    upper = slot[slot_count - 1] - slot[0];
    while (lower < upper) {
      inter = (lower + upper + 1) / 2;
      for (i = 1, j = 1, k = slot[0]; i < slot_count; ++i) {
        if (slot[i] - k >= inter) {
          k = slot[i];
          j++;
        }
      }
      if (j >= item_count) {
        lower = inter;

      } else {
        upper = inter - 1;
      }
    }
    printf("%d\n", lower);
  }
  return 0;
}
