#include <stdio.h>
#include <string.h>
#define X(u,v) printf("%d\n", (int []){u, v}[b % 2])
#define Y(u,v,w,x) printf("%d\n", (int []){u, v, w, x}[b % 4])
int main(int argc, char * argv[]) {
  int t;
  char a[1001];
  long long b;
  int c;
  scanf("%d", &t);
  while (t--) {
    scanf("%s%lld", a, &b);
    if (b == 0LL) {
      printf("1\n");
      continue;
    }
    c = a[strlen(a) - 1] - '0';
    if (c == 0 || c == 1 || c == 5 || c == 6) printf("%d\n", c);
    else if (c == 4) X(6, 4);
    else if (c == 9) X(1, 9);
    else if (c == 2) Y(6, 2, 4, 8);
    else if (c == 3) Y(1, 3, 9, 7);
    else if (c == 7) Y(1, 7, 9, 3);
    else Y(6, 8, 4, 2);
  }
  return 0;
}
