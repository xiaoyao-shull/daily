#include <stdio.h>

#define MAX_SIZE 300000

int main(int argc, char * argv[]) {
  int size;
  long long gold;
  long long array[MAX_SIZE];
  int i, j;
  long long k;
  long long max = -1;
  scanf("%d%lld", &size, &gold);
  for (i = 0; i < size; ++i) {
    scanf("%lld", &array[i]);
  }
  i = 0;
  j = 0;
  k = 0;
  while (j < size) {
    if (k + array[j] <= gold) {
      k += array[j];
      j++;

    } else {
      k -= array[i];
      i++;
    }
    max = max > k ? max : k;
  }
  printf("%lld\n", max);
  return 0;
}
