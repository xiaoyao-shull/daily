#include <stdio.h>

void run(int case_index) {
  double radius;
  scanf("%lf", &radius);
  printf("Case %d: %.2lf\n", case_index, radius * radius * 4 + 0.25);
}

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  scanf("%d", &case_count);
  for (case_index = 1; case_index <= case_count; ++case_index) {
    run(case_index);
  }
  return 0;
}
