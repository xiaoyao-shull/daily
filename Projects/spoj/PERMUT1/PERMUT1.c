#include <stdio.h>
#include <string.h>

void run() {
  int n, m;
  int i, j, k;
  int array1[256];
  int array2[256];
  int size;
  int size2;

  scanf("%d%d", &n, &m);

  memset(array1, 0, sizeof(array1));
  i = 1;
  size = 1;
  array1[0] = 1;

  while (i < n) {
    memset(array2, 0, sizeof(array2));
    i++;
    for (j = 0; j < i; ++j) {
      for (k = 0; k < size; ++k) {
        array2[j + k] += array1[k];
      }
    }
    size = i + size - 1;
    memcpy(array1, array2, sizeof(int) * 256);
  }

  if (size < m) {
    printf("0\n");

  } else {
    printf("%d\n", array1[m]);
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
