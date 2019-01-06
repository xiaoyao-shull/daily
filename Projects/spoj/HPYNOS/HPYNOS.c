#include <stdio.h>

int get_squre(int x) {
  return x * x;
}

int get_digest(int number) {
  int digest = 0;
  while (number > 0) {
    digest += get_squre(number % 10);
    number /= 10;
  }
  return digest;
}

int main(int argc, char * argv[]) {
  int mark[1024] = { 0 };
  int number;
  int digest;
  int times = 0;
  scanf("%d", &number);
  while (1) {
    digest = get_digest(number);
    times++;
    if (digest == 1) {
      printf("%d\n", times);
      break;
    }
    if (mark[digest] == 1) {
      printf("-1\n");
      break;
    }
    mark[digest] = 1;
    number = digest;
  }
  return 0;
}
