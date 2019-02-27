#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000
#define MOD 1000000007LL

char buffer[MAX_LENGTH + 1];
int previous[26];
long long count[MAX_LENGTH + 1];

void run() {
  int i, j, k;
  scanf("%s", buffer);
  memset(previous, -1, sizeof(previous));
  count[0] = 1LL;
  for (i = 1, j = strlen(buffer); i <= j; ++i) {
    k = buffer[i - 1] - 'A';
    count[i] = count[i - 1] * 2;
    count[i] %= MOD;
    if (previous[k] != -1) {
      count[i] -= count[previous[k] - 1];
    }
    previous[k] = i;
    count[i] += MOD;
    count[i] %= MOD;
  }
  printf("%lld\n", count[j]);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
