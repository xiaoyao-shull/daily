#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct segitem_t {
  int lo;
  int hi;
  int sum;
  int max;
  int lmax;
  int rmax;
};

struct segtree_t {
  struct segitem_t * items;
};

typedef struct segtree_t * segtree_t;

int max_2(int x, int y) {
  return x > y ? x : y;
}

int max_3(int x, int y, int z) {
  return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

void segtree_make_item(segtree_t tree, int idx, int lo, int hi, int * array) {
  if (lo == hi) {
    tree->items[idx].lo = lo;
    tree->items[idx].hi = hi;
    tree->items[idx].sum = array[lo];
    tree->items[idx].max = array[lo];
    tree->items[idx].lmax = array[lo];
    tree->items[idx].rmax = array[lo];
    return;
  }

  int mid = (lo + hi) / 2;
  int lidx = idx * 2;
  int ridx = idx * 2 + 1;
  segtree_make_item(tree, lidx, lo, mid, array);
  segtree_make_item(tree, ridx, mid + 1, hi, array);

  tree->items[idx].lo = lo;
  tree->items[idx].hi = hi;
  tree->items[idx].sum = tree->items[lidx].sum + tree->items[ridx].sum;
  tree->items[idx].max = max_3(tree->items[lidx].max,
                               tree->items[ridx].max,
                               tree->items[lidx].rmax + tree->items[ridx].lmax);

  tree->items[idx].lmax = max_2(tree->items[lidx].lmax,
                                tree->items[lidx].sum + tree->items[ridx].lmax);

  tree->items[idx].rmax = max_2(tree->items[ridx].rmax,
                                tree->items[ridx].sum + tree->items[lidx].rmax);
}

segtree_t segtree_make(int * array, int size) {
  struct segtree_t * ptr = malloc(sizeof(*ptr) + sizeof(struct segitem_t) * (4 * size + 1));
  ptr->items = (struct segitem_t *) (ptr + 1);
  memset(ptr->items, 0, sizeof(struct segitem_t) * (4 * size + 1));
  segtree_make_item(ptr, 1, 1, size, array);
  return ptr;
}

#define DIRECTION_LEFT 1
#define DIRECTION_RIGHT 2
#define DIRECTION_NONE 3

int segtree_max_aux(segtree_t tree, int idx, int lo, int hi, int direction) {
  if (tree->items[idx].lo == lo && tree->items[idx].hi == hi) {
    if (direction == DIRECTION_LEFT) {
      return tree->items[idx].lmax;

    } else if (direction == DIRECTION_RIGHT) {
      return tree->items[idx].rmax;

    } else {
      return tree->items[idx].max;
    }
  }
  int mid = (tree->items[idx].lo + tree->items[idx].hi) / 2;
  int lidx = idx * 2;
  int ridx = idx * 2 + 1;
  if (lo >= mid + 1) { // fall in right
    return segtree_max_aux(tree, ridx, lo, hi, direction);

  } else if (hi <= mid) { // fall in left
    return segtree_max_aux(tree, lidx, lo, hi, direction);

  } else { // contains boundary
    if (direction == DIRECTION_LEFT) {
      return max_2(tree->items[lidx].lmax,
                   tree->items[lidx].sum + segtree_max_aux(tree, ridx, mid + 1, hi, direction));

    } else if (direction == DIRECTION_RIGHT) {
      return max_2(tree->items[ridx].rmax,
                   tree->items[ridx].sum + segtree_max_aux(tree, lidx, lo, mid, direction));

    } else {
      return max_3(segtree_max_aux(tree, lidx, lo, mid, direction),
                   segtree_max_aux(tree, ridx, mid + 1, hi, direction),
                   segtree_max_aux(tree, lidx, lo, mid, DIRECTION_RIGHT) + segtree_max_aux(tree, ridx, mid + 1, hi, DIRECTION_LEFT));
    }
  }
}

int segtree_max(segtree_t tree, int lo, int hi) {
  return segtree_max_aux(tree, 1, lo, hi, DIRECTION_NONE);
}

#define MAX_SIZE 50000
int main(int argc, char * argv[]) {
  int array[MAX_SIZE + 1];
  int size;
  int i, j, k;
  scanf("%d", &size);
  for (i = 1; i <= size; ++i) {
    scanf("%d", &array[i]);
  }
  segtree_t tree = segtree_make(array, size);
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d%d", &j, &k);
    printf("%d\n", segtree_max(tree, j, k));
  }
  return 0;
}
