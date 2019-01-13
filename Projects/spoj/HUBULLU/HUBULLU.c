#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  int case_count;
  int n, p;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &n, &p);
    printf("%s\n", p == 0 ? "Airborne wins." : "Pagfloyd wins.");
  }
  return 0;
}
