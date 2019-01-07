#include <string.h>
#include <stdio.h>

#define MAX_LENGTH 2000

char s[MAX_LENGTH + 1];
char t[MAX_LENGTH + 1];
int m[(MAX_LENGTH + 1) * (MAX_LENGTH + 1)];

int min_3(int x, int y, int z) {
  return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

void run() {
  int i, j;
  int p, q;
  int d;
  scanf("%s%s", s, t);
  memset(m, 0, sizeof(m));
  p = strlen(s);
  q = strlen(t);
  for (i = 1; i <= p; ++i) {
    m[i * q + 0] = i;
  }
  for (i = 1; i <= q; ++i) {
    m[0 * q + i] = i;
  }
  for (i = 1; i <= p; ++i) {
    for (j = 1; j <= q; ++j) {
      d = s[p - i] == t[q - j] ? 0 : 1;
      m[i * q + j] = min_3(m[(i - 1) * q + (j - 1)] + d, m[(i - 1) * q + j] + 1, m[i * q + (j - 1)] + 1);
    }
  }
  printf("%d\n", m[p * q + q]);
}

int main(int argc, char * argv[]) {
  int n;
  scanf("%d", &n);
  while (n--) {
    run();
  }
}
