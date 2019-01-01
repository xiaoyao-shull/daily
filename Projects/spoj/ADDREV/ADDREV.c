#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer1[1024];
char buffer2[1024];
char buffer3[1024];

int main(int argc, char * argv[]) {
  int i, j, k;
  int u, v, w;
  int p, q, r;
  char t;
  scanf("%d", &i);
  while (i--) {
    memset(buffer1, 0, sizeof(buffer1));
    memset(buffer2, 0, sizeof(buffer2));
    memset(buffer3, 0, sizeof(buffer3));
    scanf("%s%s", buffer1, buffer2);
    u = strlen(buffer1);
    v = strlen(buffer2);
    for (j = 0, k = 0; j < u || j < v; ++j) {
      p = (j < u) ? (buffer1[j] - '0') : 0;
      q = (j < v) ? (buffer2[j] - '0') : 0;
      r = p + q + k;
      k = r / 10;
      buffer3[j] = r % 10 + '0';
    }
    if (k == 1) {
      buffer3[j] = '1';
    }
    j = 0;
    while (buffer3[j] == '0') {
      j++;
    }
    printf("%s\n", &buffer3[j]);
  }
  return 0;
}
