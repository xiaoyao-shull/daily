#include <stdio.h>

#define MOD 10000

int gcd(int a, int b) {
  int t;
  while (b > 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int read() {
  char buffer[64];
  int i, j, k;
  scanf("%s", buffer);
  for (i = 0; buffer[i] != '\0' && buffer[i] != '.'; ++i);
  if (buffer[i] == '\0') {
    return 10000;
  }
  for (i = i + 1, j = 0, k = 0; buffer[i] != '\0'; ++i) {
    j *= 10;
    j += buffer[i] - '0';
    k++;
  }
  while (k < 4) {
    j *= 10;
    k++;
  }
  return j == 0 ? 10000 : j;
}

int main(int argc, char * argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", MOD / gcd(MOD, read()));
  }
  return 0;
}
