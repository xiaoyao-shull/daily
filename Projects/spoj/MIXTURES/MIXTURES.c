#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct state_t {
  int color;
  int smoke;

} state_t;

state_t states[MAX_SIZE * MAX_SIZE];
int colors[MAX_SIZE];

state_t get_state(int lower, int upper) {
  return states[lower * MAX_SIZE + upper];
}

void set_state(int lower, int upper, state_t state) {
  states[lower * MAX_SIZE + upper] = state;
}

void clear_states() {
  memset(states, -1, sizeof(states));
}

state_t mix(state_t x, state_t y) {
  state_t z;
  z.smoke = x.smoke + y.smoke + x.color * y.color;
  z.color = (x.color + y.color) % 100;
  return z;
}

state_t dp(int lower, int upper) {
  state_t x;
  state_t y;
  state_t z;
  state_t m;
  int i;
  if (lower == upper) {
    z.smoke = 0;
    z.color = colors[lower];
    set_state(lower, upper, z);
    return z;
  }

  z = get_state(lower, upper);
  if (z.color >= 0) {
    return z;
  }

  for (i = lower; i < upper; ++i) {
    x = dp(lower, i);
    y = dp(i + 1, upper);
    m = mix(x, y);
    if (i == lower || z.smoke > m.smoke) {
      z = m;
    }
  }
  set_state(lower, upper, z);
  return z;
}

int main(int argc, char * argv[]) {
  int i;
  int size;
  int array[MAX_SIZE];
  while (scanf("%d", &size) > 0) {
    for (i = 0; i < size; ++i) {
      scanf("%d", &colors[i]);
    }
    clear_states();
    printf("%d\n", dp(0, size - 1).smoke);
  }
  return 0;
}
