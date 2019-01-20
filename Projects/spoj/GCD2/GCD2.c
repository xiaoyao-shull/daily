#include <stdio.h>
#include <string.h>
int gcd(int a, int b) {
	if (b == 0) {
		return a;

  } else {
		return gcd(b, a % b);
  }
}

int mod(char * x, int y) {
  int i, j, k;
  for (i = 0, j = strlen(x), k = 0; i < j; ++i) {
    k *= 10;
    k += (x[i] - '0');
    if (k > y) {
      k %= y;
    }
  }
  return k;
}

int main(int argc, char * argv[]) {
  int t;
  char b[256];
  int a;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &a, b);
    if (a == 0) {
      printf("%s\n", b);

    } else if (b[0] == '0') {
      printf("%d\n", a);

    } else {
      printf("%d\n", gcd(a, mod(b, a)));
    }
  }
  return 0;
}
