#include <stdio.h>

int main(int argc, char * argv[]) {
  int i, k;
  double j;
  int map[521] = { 0 };
  for (i = 1; i <= 276; ++i) {
    j += 1.0 / (i + 1);
    k = (int) (j * 100);
    if (map[k] == 0) {
      map[k] = i;
    }
  }
  for (i = 520, j = map[i]; i >= 0; --i) {
    if (map[i] == 0) {
      map[i] = j;

    } else {
      j = map[i];
    }
  }
  while (scanf("%d.%d", &i, &k), i > 0 || k > 0) {
    printf("%d card(s)\n", map[i * 100 + k]);
  }
  return 0;
}
