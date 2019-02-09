#include <stdio.h>

#define MAX_SIZE 2000

int array1[MAX_SIZE];
int array2[MAX_SIZE];
int size1;
int size2;
int state[(MAX_SIZE + 1) * (MAX_SIZE + 1)];

int max(int x, int y, int z) {
  return x > y
    ? (x > z ? x : z)
    : (y > z ? y : z);
}

void set_state(int i, int j, int k) {
  state[i * (MAX_SIZE + 1) + j] = k;
}

int get_state(int i, int j) {
  return state[i * (MAX_SIZE + 1) + j];
}

int lcs() {
  int i, j, k;
  for (i = 0; i <= size1; ++i) {
    set_state(i, 0, 0);
  }
  for (i = 0; i <= size2; ++i) {
    set_state(0, i, 0);
  }
  for (j = 1; j <= size2; ++j) {
    for (i = 1; i <= size1; ++i) {
      k = array1[i - 1] == array2[j - 1] ? 1 : 0;
      set_state(i, j, max(k + get_state(i - 1, j - 1), get_state(i - 1, j), get_state(i, j - 1)));
    }
  }
  return get_state(size1, size2);
}

void run() {
  int i, j, k;
  size1 = 0;
  while (scanf("%d", &i), i != 0) {
    array1[size1++] = i;
  }
  k = 0;
  while (scanf("%d", &i), i != 0) {
    size2 = 0;
    do {
      array2[size2++] = i;

    } while (scanf("%d", &i), i != 0);

    j = lcs();
    if (k < j) {
      k = j;
    }
  }
  printf("%d\n", k);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
