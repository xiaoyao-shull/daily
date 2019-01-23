#include <stdio.h>
#include <stdlib.h>

int min(int * array, int size) {
  int i, j;
  for (i = 1, j = 0; i < size; ++i) {
    if (array[j] > array[i]) {
      j = i;
    }
  }
  return array[j];
}

int main(int argc, char * argv[]) {
  int a, b, c;
  int d, e, f;
  int uu, vv, ww;
  int u, v, w;
  int i;
  int n;
  int case_index = 0;
  int array[14];
  while (scanf("%d", &n), n > 0) {
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    u = b + d;

    array[0] = b + d + e;
    array[1] = b + e;
    array[2] = b + c + e;
    v = min(array, 3);

    array[0] += f;
    array[1] += f;
    array[2] += f;
    array[3] = b + f;
    array[4] = b + c + f;
    w = min(array, 5);

    for (i = 3; i <= n; ++i) {
      a = d;
      b = e;
      c = f;
      uu = u;
      vv = v;
      ww = w;
      scanf("%d%d%d", &d, &e, &f);

      array[0] = uu + d;
      array[1] = uu + b + d;
      array[2] = vv + d;
      u = min(array, 3);

      array[0] += e;
      array[1] += e;
      array[2] += e;
      array[3] = uu + e;
      array[4] = uu + b + e;
      array[5] = uu + b + c + e;
      array[6] = vv + e;
      array[7] = vv + c + e;
      array[8] = ww + e;
      v = min(array, 9);

      array[0] += f;
      array[1] += f;
      array[2] += f;
      array[3] += f;
      array[4] += f;
      array[5] += f;
      array[6] += f;
      array[7] += f;
      array[8] += f;
      array[9] = uu + b + f;
      array[10] = uu + b + c + f;
      array[11] = vv + f;
      array[12] = vv + c + f;
      array[13] = ww + f;
      w = min(array, 14);
    }
    printf("%d. %d\n", ++case_index, v);
  }
  return 0;
}
