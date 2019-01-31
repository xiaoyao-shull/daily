#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int quick_sort_partition(char * array, int lower, int upper) {
  char pivot = array[(lower + upper) / 2];
  int i = lower - 1;
  int j = upper + 1;
  char temp;
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

void quick_sort(char * array, int lower, int upper) {
  if (lower >= upper) {
    return;
  }
  int inter = quick_sort_partition(array, lower, upper);
  quick_sort(array, lower, inter);
  quick_sort(array, inter + 1, upper);
}

int main(int argc, char * argv[]) {
  char word1[MAX_LENGTH + 1];
  char word2[MAX_LENGTH + 1];
  char common[MAX_LENGTH + 1];
  int length1;
  int length2;
  int i, j, k;
  while (scanf("%s%s", word1, word2) > 0) {
    length1 = strlen(word1);
    length2 = strlen(word2);
    quick_sort(word1, 0, length1 - 1);
    quick_sort(word2, 0, length2 - 1);
    i = 0;
    j = 0;
    k = 0;
    while (i < length1 && j < length2) {
      if (word1[i] < word2[j]) {
        i++;
        continue;
      }
      if (word1[i] > word2[j]) {
        j++;
        continue;
      }
      common[k] = word1[i];
      i++;
      j++;
      k++;
    }
    common[k] = '\0';
    printf("%s\n", common);
  }
  return 0;
}
