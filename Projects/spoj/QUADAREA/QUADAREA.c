#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[]) {
  int case_count;
  double a, b, c, d;
  double s;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    s = (a + b + c + d) / 2;
    printf("%.2lf\n", sqrt((s - a) * (s - b) * (s - c) * (s - d)));
  }
  return 0;
}
