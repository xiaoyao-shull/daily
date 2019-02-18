#include <stdio.h>
#include <string.h>

#define MAX_SIZE 4000000
#define MAX_RECAMAN_SIZE 500000

int exist[MAX_SIZE + 1];
int recaman[MAX_RECAMAN_SIZE + 1];

int max(x, y) { return x > y ? x : y; }

int main(int argc, char * argv[]) {
  int i;
  memset(exist, 0, sizeof(exist));
  recaman[0] = 0;
  for (i = 1; i <= MAX_RECAMAN_SIZE; ++i) {
    if (recaman[i - 1] - i > 0 && !exist[recaman[i - 1] - i]) {
      exist[recaman[i - 1] - i] = 1;
      recaman[i] = recaman[i - 1] - i;

    } else {
      exist[recaman[i - 1] + i] = 1;
      recaman[i] = recaman[i - 1] + i;
    }
  }
  while (scanf("%d", &i), i > 0) {
    printf("%d\n", recaman[i]);
  }
  return 0;
}
