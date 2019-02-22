#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct number_t {
  int digits[1024];
  int length;
  int remainder;

} number_t;

typedef struct deque_t {
  int capacity;
  int head;
  int tail;
  number_t * numbers;

} * deque_t;

deque_t deque_make(int capacity) {
  struct deque_t * ptr = malloc(sizeof(*ptr) + sizeof(number_t) * (capacity + 1));
  ptr->head = 0;
  ptr->tail = 0;
  ptr->capacity = capacity;
  ptr->numbers = (number_t *) (ptr + 1);
  return ptr;
}

void deque_push_back(deque_t deque, number_t number) {
  deque->numbers[deque->tail] = number;
  deque->tail++;
  if (deque->tail == (deque->capacity + 1)) {
    deque->tail = 0;
  }
}

number_t deque_pop_front(deque_t deque) {
  number_t number = deque->numbers[deque->head];
  deque->head++;
  if (deque->head == (deque->capacity + 1)) {
    deque->head = 0;
  }
  return number;
}

void deque_clear(deque_t deque) {
  deque->head = 0;
  deque->tail = 0;
}

int deque_size(deque_t deque) {
  if (deque->tail >= deque->head) {
    return deque->tail - deque->head;

  } else {
    return deque->tail - deque->head + (deque->capacity + 1);
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  int mod;
  deque_t deque = deque_make(20000);
  number_t number;
  int i;
  int remainder;
  int remainder_visited[20000];
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &mod);
    number.digits[0] = 1;
    number.length = 1;
    number.remainder = 1 % mod;

    deque_clear(deque);
    deque_push_back(deque, number);
    memset(remainder_visited, 0, sizeof(remainder_visited));
    while (1) {
      number = deque_pop_front(deque);
      remainder = number.remainder;
      if (remainder == 0) {
        for (i = 0; i < number.length; ++i) {
          printf("%d", number.digits[i]);
        }
        printf("\n");
        break;

      } else if (!remainder_visited[remainder]) {
        number.length++;
        number.digits[number.length - 1] = 0;
        number.remainder = remainder * 10 % mod;
        deque_push_back(deque, number);
        number.digits[number.length - 1] = 1;
        number.remainder = (remainder * 10 + 1) % mod;
        deque_push_back(deque, number);
        remainder_visited[remainder] = 1;
      }
    }
  }
  return 0;
}
