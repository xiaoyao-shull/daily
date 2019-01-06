#include <stdio.h>
#include <stdlib.h>

// begin: stack module
struct Stack {
  int capacity;
  int size;
  int * data;

};
typedef struct Stack * Stack;

Stack stack_make(int capacity) {
  struct Stack * ptr = malloc(sizeof(*ptr) + sizeof(int) * capacity);
  ptr->capacity = capacity;
  ptr->size = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}

void stack_free(Stack * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void stack_push(Stack stack, int item) {
  stack->data[stack->size] = item;
  stack->size++;
}

void stack_pop(Stack stack) {
  stack->size--;
}

int Stackop(Stack stack) {
  return stack->data[stack->size - 1];
}

int stack_size(Stack stack) {
  return stack->size;
}

void stack_clear(Stack stack) {
  stack->size = 0;
}
// end: stack module

#define MAX_ITEM_COUNT 1000

int main(int argc, char * argv[]) {
  int i, j;
  int item_count;
  int item[MAX_ITEM_COUNT];
  Stack stack = stack_make(MAX_ITEM_COUNT);
  while (scanf("%d", &item_count), item_count > 0) {
    for (i = 0; i < item_count; ++i) {
      scanf("%d", &item[i]);
    }
    stack_clear(stack);
    for (i = 0, j = 1; i < item_count; ++i) {
      if (item[i] == j) {
        j++;
        while (stack_size(stack) > 0 && Stackop(stack) == j) {
          stack_pop(stack);
          j++;
        }

      } else {
        stack_push(stack, item[i]);
      }
    }
    printf("%s\n", stack_size(stack) > 0 ? "no" : "yes");
  }
  return 0;
}
