#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_loop(int base) {
  int i, j;
  int k[10];
  memset(k, 0, sizeof(k));
  i = base % 10;
  j = 1;
  k[i] = 1;
  while (1) {
    i = base * i % 10;
    if (k[i] > 0) {
      return j;
    }
    k[i] = 1;
    j++;
  }
}

void run() {
  int b;
  int i;
  int l;
  int r;
  scanf("%d%d", &b, &i);
  if (b == 0) {
    printf("0\n");
    return;
  }
  if (i == 0) {
    printf("1\n");
    return;
  }
  l = get_loop(b);
  i = i % l + l;
  r = b % 10;
  while (--i) {
    r = r * b % 10;
  }
  printf("%d\n", r);
}

int main(int argc, char * argv[]) {
  int n;
  scanf("%d", &n);
  while (n--) {
    run();
  }
  return 0;
}
