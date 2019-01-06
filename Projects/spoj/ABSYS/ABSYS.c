#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char x[1024];
char y[1024];
char z[1024];

int to_number(char * buffer) {
  int i, j, k;
  for (i = 0, j = strlen(buffer), k = 0; i < j; ++i) {
    k = k * 10 + (buffer[i] - '0');
  }
  return k;
}

int main(int argc, char * argv[]) {
  int case_count;
  int u, v, w;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%s + %s = %s", x, y, z);
    if (strstr(x, "machula") != NULL) {
      v = to_number(y);
      w = to_number(z);
      u = w - v;
      printf("%d + %d = %d\n", u, v, w);

    } else if (strstr(y, "machula") != NULL) {
      u = to_number(x);
      w = to_number(z);
      v = w - u;
      printf("%d + %d = %d\n", u, v, w);

    } else {
      u = to_number(x);
      v = to_number(y);
      w = u + v;
      printf("%d + %d = %d\n", u, v, w);
    }
  }
  return 0;
}
