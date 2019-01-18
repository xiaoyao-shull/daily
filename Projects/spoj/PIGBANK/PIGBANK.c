#include <stdio.h>
#include <string.h>

typedef struct coin_t {
  int value;
  int weight;

} coin_t;

void sort(coin_t * coins, int size) {
  coin_t tmp;
  int new_size;
  int i;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (coins[i - 1].weight > coins[i].weight) {
        tmp = coins[i - 1];
        coins[i - 1] = coins[i];
        coins[i] = tmp;
        new_size = i;
      }
    }
    size = new_size;
  }
}

#define IMPOSSIBLE_STATE -2
#define MAX_TOTAL_WEIGHT 9999
#define MAX_COIN_COUNT 500

int states[MAX_TOTAL_WEIGHT + 1];

void clear_states() {
  memset(states, -1, sizeof(states));
}

void set_state(int weight, int value) {
  states[weight] = value;
}

int get_state(int weight) {
  return states[weight];
}

int has_state(int weight) {
  return states[weight] >= 0 || states[weight] == IMPOSSIBLE_STATE;
}

int dp(coin_t * coins, int coin_count, int weight) {
  if (weight == 0) {
    return 0;
  }
  int i, j;
  int p, q;
  if (has_state(weight)) {
    return get_state(weight);
  }
  for (i = 0, j = IMPOSSIBLE_STATE; i < coin_count && coins[i].weight <= weight; ++i) {
    p = dp(coins, coin_count, weight - coins[i].weight);
    if (p == IMPOSSIBLE_STATE) {
      continue;
    }
    q = coins[i].value + p;
    if (j == IMPOSSIBLE_STATE || j > q) {
      j = q;
    }
  }
  set_state(weight, j);
  return j;
}

int main(int argc, char * argv[]) {
  int case_count;
  int coin_count;
  coin_t coins[MAX_COIN_COUNT];
  int empty, full;
  int value;
  int i;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &empty, &full);
    scanf("%d", &coin_count);
    for (i = 0; i < coin_count; ++i) {
      scanf("%d%d", &coins[i].value, &coins[i].weight);
    }
    sort(coins, coin_count);
    clear_states();

    value = dp(coins, coin_count, full - empty);
    if (value == IMPOSSIBLE_STATE) {
      printf("This is impossible.\n");

    } else {
      printf("The minimum amount of money in the piggy-bank is %d.\n", value);
    }
  }
  return 0;
}
