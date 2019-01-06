#include <stdio.h>

#define MODULE 1000007L

void run() {
  long n;
  scanf("%ld", &n);
  printf("%ld\n", (n * n * 3L + n) / 2L % MODULE);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while(case_count--) {
    run();
  }
  return 0;
}
