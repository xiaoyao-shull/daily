#include <stdio.h>

#define MAX_SIZE 100000

int main(int argc, char * argv[]) {
  int i, j;
  int size;
  int array[MAX_SIZE + 1];
  int order[MAX_SIZE + 1];
  while (scanf("%d", &size), size > 0) {
    for (i = 1; i <= size; ++i) {
      scanf("%d", &j);
      array[i] = j;
      order[j] = i;
    }
    for (i = 1; i <= size; ++i) {
      if (array[i] != order[i]) {
        break;
      }
    }
    printf("%s\n", i <= size ? "not ambiguous" : "ambiguous");
  }
  return 0;
}
