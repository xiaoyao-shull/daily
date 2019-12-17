#include <stdio.h>
#include <stdlib.h>

#define MAX_USER_COUNT 100000

int parent[MAX_USER_COUNT + 1];
int size[MAX_USER_COUNT + 1];

void init(int user_count);
void join(int i, int j, int max_size);
int find(int i);

void init(int user_count) {
  int i;
  for (i = 1; i <= user_count; i++) {
    parent[i] = i;
    size[i] = 1;
  }
}

void join(int i, int j, int max_size) {
  i = find(i);
  j = find(j);
  if (size[i] + size[j] > max_size) {
    return;
  }

  if (size[i] > size[j]) {
    parent[j] = i;
    size[i] += size[j];

  } else {
    parent[i] = j;
    size[j] += size[i];
  }
}

int find(int i) {
  while (parent[i] != i) {
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}

int main(int argc, char * argv[]) {
  int user_count;
  int max_size;
  int query_count;
  int i, j, k;
  char operation[2];
  scanf("%d%d%d", &user_count, &max_size, &query_count);
  init(user_count);
  for (int i = 0; i < query_count; i++) {
    scanf("%s", operation);
    switch(operation[0]) {
    case 'A':
      scanf("%d%d", &j, &k);
      join(j, k, max_size);
      break;

    case 'E':
      scanf("%d%d", &j, &k);
      if (find(j) == find(k)) {
        printf("Yes\n");

      } else {
        printf("No\n");
      }
      break;

    case 'S':
      scanf("%d", &j);
      printf("%d\n", size[find(j)]);
    default:
      break;
    }
  }
  return 0;
}
