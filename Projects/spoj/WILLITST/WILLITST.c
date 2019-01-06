#include <stdio.h>

int is_loop(long n) {
  while (n > 1L) {
    if (n == 3) {
      return 1;
    }
    if (n % 2L == 0) {
      n = n / 2L;
    } else {
      n = n * 3L + 3L;
    }
  }
  return 0;
}

int main(int argc, char * argv[]) {
  long n;
  scanf("%ld", &n);
  printf("%s\n", is_loop(n) ? "NIE" : "TAK");
  return 0;
}
