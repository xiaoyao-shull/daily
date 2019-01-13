#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTY_COUNT 100
#define MAX_BUDGET 500

struct state_t {
  int fee;
  int fun;
};
typedef struct state_t state_t;

state_t states[(MAX_BUDGET + 1) * (MAX_PARTY_COUNT + 1)];

state_t get_state(int budget, int party) {
  return states[budget * (MAX_PARTY_COUNT + 1) + party];
}

void set_state(int budget, int party, state_t state) {
  states[budget * (MAX_PARTY_COUNT + 1) + party] = state;
}

void clear_states() {
  memset(states, -1, sizeof(states));
}

int party_fee[MAX_PARTY_COUNT + 1];
int party_fun[MAX_PARTY_COUNT + 1];

state_t dp_fun(int budget, int party, int party_count) {
  state_t p;
  state_t q;
  state_t state;
  state = get_state(budget, party);
  if (state.fun != -1) {
    return state;
  }
  if (party > party_count) {
    state.fee = 0;
    state.fun = 0;
    return state;
  }
  if (budget >= party_fee[party]) {
    p = dp_fun(budget - party_fee[party], party + 1, party_count);
    p.fee += party_fee[party];
    p.fun += party_fun[party];
    q = dp_fun(budget, party + 1, party_count);
    if (p.fun > q.fun || (p.fun == q.fun && p.fee < q.fee)) {
      set_state(budget, party, p);
      return p;

    } else {
      set_state(budget, party, q);
      return q;
    }

  } else {
    q = dp_fun(budget, party + 1, party_count);
    set_state(budget, party, q);
    return q;
  }
}

int main(int argc, char * argv[]) {
  int party_count;
  int budget;
  int i;
  while (scanf("%d%d", &budget, &party_count), budget > 0 || party_count > 0) {
    clear_states();
    for (i = 1; i <= party_count; ++i) {
      scanf("%d%d", &party_fee[i], &party_fun[i]);
    }
    state_t state = dp_fun(budget, 1, party_count);
    printf("%d %d\n", state.fee, state.fun);
  }
  return 0;
}
