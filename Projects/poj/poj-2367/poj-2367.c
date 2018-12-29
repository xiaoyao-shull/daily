#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// begin: array module interface
typedef struct array_t {
  int capacity;
  int * data;

} * array_t;

array_t array_new(int capacity);
void array_del(array_t * ptr);
void array_set(array_t array, int index, int value);
void array_increase(array_t array, int index);
void array_decrease(array_t array, int index);
int array_get(array_t array, int index);
// end: array module interface

// begin: matrix module interface
typedef struct matrix_t {
  int row;
  int col;
  int * data;
} * matrix_t;

matrix_t matrix_new(int row, int col);
void matrix_del(matrix_t * ptr);
void matrix_set(matrix_t matrix, int row, int col, int value);
int matrix_get(matrix_t matrix, int row, int col);
// end: matrix module interface

// begin: deque module interface
typedef struct deque_t {
  int capacity;
  int head;
  int tail;
  int * data;

} * deque_t;

deque_t deque_new(int capacity);
void deque_del(deque_t * ptr);
void deque_push_back(deque_t deque, int value);
void deque_push_front(deque_t deque, int value);
int deque_pop_back(deque_t deque);
int deque_pop_front(deque_t deque);
int deque_empty(deque_t deque);
int deque_size(deque_t deque);
// end: deque module interface

#define MAX_SIZE 100

/**
 * 火星人可以有任意多个父母、任意多个子女.
 * 每个火星人只知道自己的子女，不知道自己的父母.
 * 按从长辈到晚辈的顺序输出火星人的拓扑序.
 */
int main(int argc, char * argv[]) {

  array_t parent_count = array_new(MAX_SIZE + 1);
  array_t children_count = array_new(MAX_SIZE + 1);
  matrix_t children = matrix_new(MAX_SIZE + 1, MAX_SIZE + 1);
  deque_t eldest = deque_new(MAX_SIZE + 1);
  deque_t order = deque_new(MAX_SIZE + 1);

  int n;
  int i, j, k;

  // 建图
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    while (scanf("%d", &j), j > 0) {
      k = array_get(children_count, i);
      matrix_set(children, i, k, j);
      array_increase(children_count, i);
      array_increase(parent_count, j);
    }
  }

  // 初始化入度为零的点集
  for (i = 1; i <= n; ++i) {
    if (array_get(parent_count, i) == 0) {
      deque_push_back(eldest, i);
    }
  }

  // 每次从入度为零的点集中选择一个点，将其移出图
  while (!deque_empty(eldest)) {
    i = deque_pop_back(eldest);
    deque_push_back(order, i);
    for (j = 0; j < array_get(children_count, i); ++j) {
      k = matrix_get(children, i, j);
      array_decrease(parent_count, k);
      if (array_get(parent_count, k) == 0) {
        deque_push_back(eldest, k);
      }
    }
  }

  // 输出拓扑序
  while (!deque_empty(order)) {
    printf("%d", deque_pop_front(order));
    if (deque_empty(order)) {
      printf("\n");

    } else {
      printf(" ");
    }
  }

  return 0;
}

// begin: matrix module implementation
int matrix_get(matrix_t matrix, int row, int col) {
  return matrix->data[matrix->row * col + row];
}

void matrix_set(matrix_t matrix, int row, int col, int value) {
  matrix->data[matrix->row * col + row] = value;
}

void matrix_del(matrix_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

matrix_t matrix_new(int row, int col) {
  struct matrix_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * row * col);
  ptr->row = row;
  ptr->col = col;
  ptr->data = (int *) (ptr + 1);
  memset(ptr->data, 0, sizeof(int) * row * col);
  return ptr;
}
// end: matrix module implementation

// begin: deque module implementation
int deque_size(deque_t deque) {
  if (deque->tail >= deque->head) {
    return deque->tail - deque->head;

  } else {
    return deque->tail - deque->head + deque->capacity;
  }
}

int deque_empty(deque_t deque) {
  return deque->head == deque->tail;
}

int deque_pop_front(deque_t deque) {
  int value = deque->data[deque->head];
  deque->head++;
  if (deque->head == deque->capacity) {
    deque->head = 0;
  }
  return value;
}

int deque_pop_back(deque_t deque) {
  deque->tail--;
  if (deque->tail < 0) {
    deque->tail = deque->capacity - 1;
  }
  return deque->data[deque->tail];
}

void deque_push_front(deque_t deque, int value) {
  deque->head--;
  if (deque->head < 0) {
    deque->head = deque->capacity - 1;
  }
  deque->data[deque->head] = value;
}

void deque_push_back(deque_t deque, int value) {
  deque->data[deque->tail] = value;
  deque->tail++;
  if (deque->tail == deque->capacity) {
    deque->tail = 0;
  }
}

void deque_del(deque_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

deque_t deque_new(int capacity) {
  struct deque_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * capacity);
  ptr->capacity = capacity;
  ptr->head = 0;
  ptr->tail = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}
// end: deque module implementation

// begin: array module implementation
int array_get(array_t array, int index) {
  return array->data[index];
}

void array_decrease(array_t array, int index) {
  array_set(array, index, array_get(array, index) - 1);
}

void array_increase(array_t array, int index) {
  array_set(array, index, array_get(array, index) + 1);
}

void array_set(array_t array, int index, int value) {
  array->data[index] = value;
}

void array_del(array_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

array_t array_new(int capacity) {
  struct array_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * capacity);
  ptr->capacity = capacity;
  ptr->data = (int * ) (ptr + 1);
  memset(ptr->data, 0, sizeof(int) * capacity);
  return ptr;
}
// end: array module implementation
