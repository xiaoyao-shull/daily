#include <stdio.h>

int main(int argc, char * argv[]) {
  int array[10];
  int i, j;
  for (i = 0; i < 10; ++i) {
    scanf("%d", &array[i]);
  }
  for (i = 0, j = 0; i < 10; ++i) {
    if (j + array[i] <= 100) {
      j += array[i];

    } else {
      if ((j + array[i] - 100) <= (100 - j)) {
        j += array[i];
      }
      break;
    }
  }
  printf("%d\n", j);
  return 0;
}
