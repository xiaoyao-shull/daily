#include <math.h>
#include <stdio.h>

int gcd(int a, int b) {
  int temp;
  while (b > 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main(int argc, char * argv[]) {
  int case_count;
  int x, y, z;
  int i, j, k;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &x, &y);
    z = gcd(x, y);

    k = sqrt(z);
    for (i = 1, j = 0; i <= k; ++i) {
      if (z % i == 0) {
        j += 2;
      }
    }
    if (k * k == z) {
      j--;
    }
    printf("%d\n", j);
  }
  return 0;
}
