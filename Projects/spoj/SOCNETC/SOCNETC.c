#include <stdio.h>
#include <stdlib.h>

struct uf_t {
  int * parent;
  int * weight;
};
typedef struct uf_t * uf_t;

uf_t uf_create(int size);
void uf_delete(uf_t * ptr);
int uf_root(uf_t uf, int i);
int uf_size(uf_t uf, int i);
void uf_union(uf_t uf, int i, int j);

uf_t uf_create(int size) {
  int i;
  struct uf_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (size + 1) * 2);
  ptr->parent = (int *) (ptr + 1);
  ptr->weight = ptr->parent + (size + 1);
  for (i = 1; i <= size; i++) {
    ptr->parent[i] = i;
    ptr->weight[i] = 1;
  }
  return ptr;
}

void uf_delete(uf_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

int uf_root(uf_t uf, int i) {
  while (i != uf->parent[i]) {
    uf->parent[i] = uf->parent[uf->parent[i]];
    i = uf->parent[i];
  }
  return i;
}

int uf_size(uf_t uf, int i) {
  return uf->weight[uf_root(uf, i)];
}

void uf_union(uf_t uf, int i, int j) {
  i = uf_root(uf, i);
  j = uf_root(uf, j);
  if (uf_size(uf, i) > uf_size(uf, j)) {
    uf->parent[j] = i;
    uf->weight[i] += uf->weight[j];

  } else {
    uf->parent[i] = j;
    uf->weight[j] += uf->weight[i];
  }
}

int main(int argc, char * argv[]) {
  int n, m, q;
  int i, j, si, sj;
  char buffer[2];
  scanf("%d%d%d", &n, &m, &q);
  uf_t uf = uf_create(n);
  while (q--) {
    scanf("%s", buffer);
    switch(buffer[0]) {
    case 'A':
      scanf("%d%d", &i, &j);
      si = uf_size(uf, i);
      sj = uf_size(uf, j);
      if (si + sj <= m) {
        uf_union(uf, i, j);
      }
      break;

    case 'E':
      scanf("%d%d", &i, &j);
      if (uf_root(uf, i) == uf_root(uf, j)) {
        printf("Yes\n");

      } else {
        printf("No\n");
      }
      break;

    case 'S':
    default:
      scanf("%d", &i);
      printf("%d\n", uf_size(uf, i));
    }
  }
  return 0;
}
