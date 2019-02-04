#include <stdio.h>
#include <string.h>

typedef struct pair_t {
  int left;
  int right;

} pair_t;

pair_t combine(pair_t p, pair_t q) {
  int array[4];
  int size = 4;
  int new_size;
  int temp;
  int i;
  pair_t pair;
  array[0] = p.left;
  array[1] = p.right;
  array[2] = q.left;
  array[3] = q.right;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (array[i - 1] < array[i]) {
        temp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = temp;
        new_size = i;
      }
    }
    size = new_size;
  }
  pair.left = array[0];
  pair.right = array[1];
  return pair;
}

pair_t update(pair_t * tree, int tree_index, int tree_lower, int tree_upper, int array_index, int array_value) {
  int tree_inter = (tree_lower + tree_upper) / 2;
  pair_t p;
  pair_t q;
  if (array_index < tree_lower || array_index > tree_upper) {
    return tree[tree_index];
  }
  if (tree_lower == tree_upper) {
    tree[tree_index].left = array_value;
    tree[tree_index].right = -1;
    return tree[tree_index];
  }
  p = update(tree, 2 * tree_index + 1, tree_lower,     tree_inter, array_index, array_value);
  q = update(tree, 2 * tree_index + 2, tree_inter + 1, tree_upper, array_index, array_value);
  tree[tree_index] = combine(p, q);
  return tree[tree_index];
}

pair_t query(pair_t * tree, int tree_index, int tree_lower, int tree_upper, int query_lower, int query_upper) {
  int tree_inter = (tree_lower + tree_upper) / 2;
  pair_t p;
  pair_t q;
  if (query_lower > tree_upper || query_upper < tree_lower) {
    p.left = -1;
    p.right = -1;
    return p;
  }
  if (tree_lower >= query_lower && tree_upper <= query_upper) {
    return tree[tree_index];
  }
  p = query(tree, 2 * tree_index + 1, tree_lower,     tree_inter, query_lower, query_upper);
  q = query(tree, 2 * tree_index + 2, tree_inter + 1, tree_upper, query_lower, query_upper);
  return combine(p, q);
}

#define MAX_SIZE 100000

int main(int argc, char * argv[]) {
  int size;
  pair_t tree[4 * MAX_SIZE];
  int index, value;
  int lower, upper;
  int command_count;
  char command[2];
  pair_t p;
  memset(tree, -1, sizeof(tree));
  scanf("%d", &size);
  for (index = 0; index < size; ++index) {
    scanf("%d", &value);
    update(tree, 0, 0, size - 1, index, value);
  }
  scanf("%d", &command_count);
  while (command_count--) {
    scanf("%s", command);
    if (command[0] == 'U') {
      scanf("%d%d", &index, &value);
      index--;
      update(tree, 0, 0, size - 1, index, value);

    } else {
      scanf("%d%d", &lower, &upper);
      lower--;
      upper--;
      p = query(tree, 0, 0, size - 1, lower, upper);
      printf("%d\n", p.left + p.right);
    }
  }
  return 0;
}
