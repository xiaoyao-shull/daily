#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char x[128];
char y[128];
char z[128];

void flip(char * string) {
  int i;
  int j;
  char c;
  for (i = 0, j = strlen(string) - 1; i < j; ++i, --j) {
    c = string[i];
    string[i] = string[j];
    string[j] = c;
  }
}

void trim(char * string) {
  int i;
  int j;
  for (i = 0, j = strlen(string); i < j; ++i) {
    if (string[i] != '0') {
      break;
    }
  }
  strcpy(string, string + i);
}

void clear() {
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(z, 0, sizeof(z));
}

int main(int argc, char * argv[]) {
  int i, j, k, m, n;
  int p, q, r;
  while (1) {
    clear();
    if (scanf("%s%s", x, y) <= 0) {
      break;
    }
    flip(x);
    flip(y);

    m = strlen(x);
    n = strlen(y);
    for (i = 0, j = 0; i < m || i < n; ++i) {
      if (i >= m) {
        p = j + (y[i] - '0');

      } else if (i >= n) {
        p = j + (x[i] - '0');

      } else {
        p = j + (x[i] - '0') + (y[i] - '0');
      }
      j = p / 10;
      z[i] = (p % 10) + '0';
    }
    if (j != 0) {
      z[i] = j + '0';
    }
    flip(z);
    for (i = 0, j = 0; i < strlen(z); ++i) {
      p = (z[i] - '0') + j * 10;
      j = p % 2;
      z[i] = p / 2 + '0';
    }
    trim(z);
    printf("%s\n", strlen(z) > 0 ? z : "0");

    memset(z, 0, sizeof(z));
    for (i = 0, j = 0; i < m || i < n; ++i) {
      if (i >= n) {
        p = (x[i] - '0') - j;

      } else {
        p = (x[i] - '0') - (y[i] - '0') - j;
      }
      if (p < 0) {
        p += 10;
        j = 1;

      } else {
        j = 0;
      }
      z[i] = p + '0';
    }
    flip(z);
    for (i = 0, j = 0; i < strlen(z); ++i) {
      p = (z[i] - '0') + j * 10;
      j = p % 2;
      z[i] = p / 2 + '0';
    }
    trim(z);
    printf("%s\n", strlen(z) > 0 ? z : "0");
  }
  return 0;
}
