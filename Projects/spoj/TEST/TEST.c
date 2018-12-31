#include <stdio.h>

int main(int argc, char * argv[]) {
  int i;
  while (scanf("%d", &i) > 0) {
    if (i == 42) {
      break;
    }
    printf("%d\n", i);
  }
  return 0;
}
