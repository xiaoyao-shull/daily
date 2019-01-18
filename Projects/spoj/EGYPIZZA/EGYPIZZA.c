#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
  return x < y ? x : y;
}

int main(int argc, char * argv[]) {
  int n;
  int x, y, z;
  int t;
  int numer, denom;
  scanf("%d", &n);
  x = 0;
  y = 0;
  z = 0;
  while (n--) {
    scanf("%d/%d", &numer, &denom);
    if (numer == 1 && denom == 4) {
      x++;
      continue;
    }
    if (numer == 1 && denom == 2) {
      y++;
      continue;
    }
    if (numer == 3 && denom == 4) {
      z++;
      continue;
    }
  }

  t = 0;
  t += z;
  x -= min(x, z);

  t += (y + 1) / 2;
  x -= min(x, 2 * (y % 2));

  t += (x + 3) / 4;

  t += 1;

  printf("%d\n", t);
  return 0;
}
