#include <stdio.h>
#include <string.h>

int state[1000001];
int k;
int l;
int m;

int dp(int m) {
  if (state[m] != -1) {
    return state[m];
  }
  if (m == k || m == l || m == 1) {
    state[m] = 1;
    return 1;
  }
  if (m > l && dp(m - l) == 0) {
    state[m] = 1;
    return 1;
  }
  if (m > k && dp(m - k) == 0) {
    state[m] = 1;
    return 1;
  }
  if (m > 1 && dp(m - 1) == 0) {
    state[m] = 1;
    return 1;
  }
  state[m] = 0;
  return 0;
}

int main(int argc, char * argv[]) {
  int case_count;
  int i;
  memset(state, -1, sizeof(state));
  scanf("%d%d", &k, &l);
  for (i = 1; i <= l; ++i) {
    dp(i);
  }
  for (i = l + 1; i <= 1000000; ++i) {
    if (state[i - 1] == 0 || state[i - k] == 0 || state[i - l] == 0) {
      state[i] = 1;

    } else {
      state[i] = 0;
    }
  }
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &m);
    printf("%c", state[m] == 1 ? 'A' : 'B');
  }
  printf("\n");
  return 0;
}
