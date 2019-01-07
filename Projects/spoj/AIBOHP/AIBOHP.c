#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 6100

int max_3(int x, int y, int z) {
  return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

int main(int argc, char * argv[]) {
  int case_count;
  char string[MAX_BUFFER + 1];
  char buffer[MAX_BUFFER + 1];
  int d1[MAX_BUFFER + 1];
  int d2[MAX_BUFFER + 1];
  int n, s;
  int i, j;
  char c;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%s", string);
    strcpy(buffer, string);
    n = strlen(string);
    for (i = 0, j = n - 1; i < j; ++i, --j) {
      c = buffer[i];
      buffer[i] = buffer[j];
      buffer[j] = c;
    }
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= n; ++j) {
        s = string[i - 1] == buffer[j - 1] ? 1 : 0;
        d2[j] = max_3(d1[j - 1] + s, d1[j], d2[j - 1]);
      }
      memcpy(d1, d2, sizeof(d2));
    }
    printf("%d\n", n - d1[n]);
  }
  return 0;
}
