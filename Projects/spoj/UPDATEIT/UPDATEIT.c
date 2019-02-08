#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000
#define MAX_UPDATE_COUNT 100000
#define MAX_QUERY_COUNT 10000

int delta[MAX_SIZE];
int array[MAX_SIZE];

void run() {
  int size;
  int i, j;
  int l, r, v;
  int query_count;
  int update_count;
  scanf("%d%d", &size, &update_count);
  memset(delta, 0, sizeof(delta));
  while (update_count--) {
    scanf("%d%d%d", &l, &r, &v);
    delta[l] += v;
    if (r + 1 < size) {
      delta[r + 1] -= v;
    }
  }
  for (i = 0, j = 0; i < size; ++i) {
    j += delta[i];
    array[i] = j;
  }

  scanf("%d", &query_count);
  while (query_count--) {
    scanf("%d", &i);
    printf("%d\n", array[i]);
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
