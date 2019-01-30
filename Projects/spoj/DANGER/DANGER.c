#include <stdio.h>

int read() {
  char buffer[5];
  int i, j;
  scanf("%s", buffer);
  i = (buffer[0] - '0') * 10 + (buffer[1] - '0');
  j = (buffer[3] - '0');
  while (j--) {
    i *= 10;
  }
  return i;
}

int main(int argc, char * argv[]) {
  int n;
  int i;
  while (n = read(), n > 0) {
    i = 0;
    while (n != (n & -n)) {
      i += (n & -n);
      n -= (n & -n);
    }
    printf("%d\n", 2 * i + 1);
  }
  return 0;
}
