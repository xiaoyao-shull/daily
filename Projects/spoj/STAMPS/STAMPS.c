#include <stdio.h>
#include <stdlib.h>

void sort(int * array, int size) {
  int i;
  int tmp;
  int new_size;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (array[i - 1] < array[i]) {
        tmp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = tmp;
        new_size = i;
      }
    }
    size = new_size;
  }
}

void run(int case_index) {
  int z, n, i;
  int x[10000];
  scanf("%d%d", &z, &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  sort(x, n);
  for (i = 0; i < n; ++i) {
    z -= x[i];
    if (z <= 0) {
      break;
    }
  }
  printf("Scenario #%d:\n", case_index);
  if (i < n) {
    printf("%d\n\n", (i + 1));

  } else {
    printf("impossible\n\n");
  }
  return;
}

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    run(case_index);
  }
  return 0;
}
