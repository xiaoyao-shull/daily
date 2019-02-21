#include <stdio.h>
#include <math.h>

#define PI (acos(-1))

// Kamenetsky’s formula
int main(int argc, char * argv[]) {
  int case_count;
  double n;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%lf", &n);
    if (n == 1 || n == 0) {
      printf("1\n");

    } else {
      printf("%lld\n", (long long) (floor((log(2 * PI * n) / 2 + n * (log(n) - 1)) / log(10)) + 1));
    }
  }

  return 0;
}
