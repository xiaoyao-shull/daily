#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __STACK_MODULE_INCLUDED__
#define __STACK_MODULE_INCLUDED__
#define T int
struct stack_t {
  int capacity;
  int size;
  T * data;
};
typedef struct stack_t * stack_t;

stack_t stack_make(int capacity) {
  struct stack_t * ptr = malloc(sizeof(*ptr) + sizeof(T) * capacity);
  ptr->capacity = capacity;
  ptr->size = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}

void stack_free(stack_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void stack_push(stack_t stack, T value) {
  stack->data[stack->size] = value;
  stack->size++;
}

void stack_pop(stack_t stack) {
  stack->size--;
}

T stack_top(stack_t stack) {
  return stack->data[stack->size - 1];
}

void stack_clear(stack_t stack) {
  stack->size = 0;
}

int stack_size(stack_t stack) {
  return stack->size;
}
#undef T
#endif // __STACK_MODULE_INCLUDED__

#define MAX_SIZE 100000

int height[MAX_SIZE];
int left[MAX_SIZE];
int right[MAX_SIZE];

int main(int argc, char * argv[]) {
  int size;
  int i, j;
  long long u, v;
  stack_t stack = stack_make(MAX_SIZE);
  while (scanf("%d", &size), size > 0) {
    for (i = 0; i < size; ++i) {
      scanf("%d", &height[i]);
    }

    stack_clear(stack);
    for (i = 0; i < size; ++i) {
      while (stack_size(stack) > 0 && height[stack_top(stack)] >= height[i]) {
        stack_pop(stack);
      }
      if (stack_size(stack) == 0) {
        left[i] = i;

      } else {
        left[i] = i - stack_top(stack) - 1;
      }
      stack_push(stack, i);
    }

    stack_clear(stack);
    for (i = size - 1; i >= 0; --i) {
      while (stack_size(stack) > 0 && height[stack_top(stack)] >= height[i]) {
        stack_pop(stack);
      }
      if (stack_size(stack) == 0) {
        right[i] = size - i - 1;

      } else {
        right[i] = stack_top(stack) - i - 1;
      }
      stack_push(stack, i);
    }

    for (i = 0, u = 0LL; i < size; ++i) {
      v = (left[i] + right[i] + 1) * (long long) height[i];
      if (u < v) {
        u = v;
      }
    }
    printf("%lld\n", u);
  }
  return 0;
}
