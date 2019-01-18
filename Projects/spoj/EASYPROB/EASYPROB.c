#include <stdio.h>

void print(int n) {
  int array[32];
  int size = 0;
  int i = 0;
  while ((1 << i) <= n) {
    if ((n & (1 << i)) > 0) {
      array[size++] = i;
    }
    i++;
  }
  for (i = size - 1; i >= 0; --i) {
    if (array[i] == 0) {
      printf("2(0)");

    } else if (array[i] == 1) {
      printf("2");

    } else {
      printf("2(");
      print(array[i]);
      printf(")");
    }
    if (i != 0) {
      printf("+");
    }
  }
}

void run(int n) {
  printf("%d=", n);
  print(n);
  printf("\n");
}

int main(int argc, char * argv[]) {
  run(137);
  run(1315);
  run(73);
  run(136);
  run(255);
  run(1384);
  run(16385);
  return 0;
}
