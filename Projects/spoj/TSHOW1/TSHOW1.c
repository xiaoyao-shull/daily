#include <stdio.h>
#include <string.h>

long long count[55];
long long total[55];
char buffer[64];

void init() {
  int i;
  count[0] = 0LL;
  count[1] = 2LL;
  for (i = 2; i < 55; ++i) {
    count[i] = count[i - 1] * 2LL;
  }
  total[0] = count[0];
  for (i = 1; i < 55; ++i) {
    total[i] = total[i - 1] + count[i];
  }
}

void print(long long value, int length) {
  int i, j;
  long long k;
  char c;
  memset(buffer, 0, sizeof(buffer));
  for (i = 0; i < length; ++i) {
    k = value % 2LL;
    value /= 2LL;
    buffer[i] = (k == 0LL) ? '5' : '6';
  }
  for (i = 0, j = length - 1; i < j; i++, j--) {
    c = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = c;
  }
  printf("%s\n", buffer);
}

int main(int argc, char * argv[]) {
  int case_total;
  int i;
  long long n;
  init();
  scanf("%d", &case_total);
  while (case_total--) {
    scanf("%lld", &n);
    for (i = 0; i < 55; ++i) {
      if (total[i] >= n) {
        break;
      }
    }
    print(n - 1 - total[i - 1], i);
  }
  return 0;
}
