#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bitree_t {
  int size;
  long long * data;
};

typedef struct bitree_t * bitree_t;

bitree_t bitree_make(int size) {
  struct bitree_t * ptr = malloc(sizeof(*ptr) + sizeof(long long) * (size + 1));
  ptr->size = size;
  ptr->data = (long long *) (ptr + 1);
  memset(ptr->data, 0, sizeof(long long) * (size + 1));
  return ptr;
}

void bitree_free(bitree_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void bitree_add(bitree_t tree, int index, long long delta) {
  while (index <= tree->size) {
    tree->data[index] += delta;
    index += index & (-index);
  }
}

long long bitree_sum(bitree_t tree, int index) {
  long long sum = 0;
  while (index >= 1) {
    sum += tree->data[index];
    index -= index & (-index);
  }
  return sum;
}

void run() {
  int array_size;
  int query_count;
  bitree_t tree1;
  bitree_t tree2;
  int command;
  int i;
  int start, end;
  long long value;
  scanf("%d%d", &array_size, &query_count);
  tree1 = bitree_make(array_size);
  tree2 = bitree_make(array_size);
  while (query_count--) {
    scanf("%d", &command);
    if (command == 0) {
      scanf("%d%d%lld", &start, &end, &value);
      bitree_add(tree1, start, value);
      bitree_add(tree1, end + 1, -value);
      bitree_add(tree2, start, value * (start - 1));
      bitree_add(tree2, end + 1, -value * end);

    } else {
      scanf("%d%d", &start, &end);
      printf("%lld\n",
             bitree_sum(tree1, end) * end -
             bitree_sum(tree2, end) -
             bitree_sum(tree1, start - 1) * (start - 1) +
             bitree_sum(tree2, start - 1));
    }
  }
  bitree_free(&tree1);
  bitree_free(&tree2);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
