#include <stdio.h>

int main(int argc, char * argv[]) {
  double n;
  while (scanf("%lf", &n), n > 0) {
    printf("%.2lf\n", n * n / 2 / 3.1415926);
  }
  return 0;
}
