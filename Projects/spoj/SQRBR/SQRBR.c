#include <stdio.h>
#include <string.h>

#define MAX_PAIR_COUNT 19

int mask[MAX_PAIR_COUNT * 2 + 1];
int state[(MAX_PAIR_COUNT + 1) * (MAX_PAIR_COUNT + 1)];
int pair_count;
int mask_count;

int get_state(int i, int j) {
  if (state[i * (MAX_PAIR_COUNT + 1) + j] != -1) {
    return state[i * (MAX_PAIR_COUNT + 1) + j];
  }
  if (i == pair_count && j == pair_count) {
    return 1;
  }
  int s = 0;
  if (i < pair_count) {
    s += get_state(i + 1, j);
  }
  if (j < pair_count && i > j && !mask[i + j + 1]) {
    s += get_state(i, j + 1);
  }
  state[i * (MAX_PAIR_COUNT + 1) + j] = s;
  return s;
}

void clear_state() {
  memset(state, -1, sizeof(state));
}


int main(int argc, char * argv[]) {
  int case_count;
  int i, j;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &pair_count, &mask_count);
    memset(mask, 0, sizeof(mask));
    for (i = 0; i < mask_count; ++i) {
      scanf("%d", &j);
      mask[j] = 1;
    }
    clear_state();
    printf("%d\n", get_state(0, 0));
  }
  return 0;
}
