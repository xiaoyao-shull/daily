#include <stdio.h>

int main(int argc, char * argv[]) {
  int t;
  int n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", (n + 1) / 2);
  }
}
