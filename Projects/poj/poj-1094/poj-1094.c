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
int array_get(array_t array, int index);
void array_clear(array_t array);
void array_increase(array_t array, int index);
void array_decrease(array_t array, int index);
void array_copy(array_t dest, array_t src);
// end: array module interface

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
int deque_pop_front(deque_t deque);
int deque_pop_back(deque_t deque);
int deque_size(deque_t deque);
void deque_clear(deque_t deque);
// end: deque module interface

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
void matrix_clear(matrix_t matrix);
// end: matrix module interface

#define NODE(c) (c - 'A')
#define CHAR(n) (n + 'A')

/*
 * 每输入一条边，对当前的图模型进行一次拓扑排序，以下三种情况下进行输出：
 * 1. 有唯一确定的拓扑序.
 * 2. 发现有向环.
 * 3. 所有边都输入后，上述两种情况均未出现.
 *
 * 需要注意的问题：
 * 1. 同时使用邻接矩阵和邻接表处理重边.
 * 2. 使用拓扑排序检测有向环需要考虑图的连通性.
 * 3. 在拓扑排序的过程中遇到有多个拓扑序的情况时应该继续执行，不然可能无法检测到有向环.
 * 4. 双端队列的实现需要注意填满时的情况.
 */
int main(int argc, char * argv[]) {
  int n; // number of nodes
  int m; // number of edges
  int p, q; // register for nodes
  int i, j; // register for numbers
  matrix_t adjacent_list = matrix_new(26, 26);
  matrix_t adjacent_matrix = matrix_new(26, 26);
  array_t indegrees = array_new(26);
  array_t outdegrees = array_new(26);
  array_t remaining_indegrees = array_new(26);
  deque_t zero_indegree_nodes = deque_new(26);
  deque_t sorted_nodes = deque_new(26);
  char buffer[4];
  int multiple_ordering;
  int solved;

  while (scanf("%d%d", &n, &m), n != 0 || m != 0) {
    array_clear(indegrees);
    array_clear(outdegrees);
    matrix_clear(adjacent_matrix);
    solved = 0;
    for (i = 0; i < m; ++i) {
      scanf("%s", buffer);
      if (solved) {
        continue;
      }
      if (matrix_get(adjacent_matrix, NODE(buffer[0]), NODE(buffer[2])) > 0) {
        continue;
      }
      matrix_set(adjacent_matrix, NODE(buffer[0]), NODE(buffer[2]), 1);
      matrix_set(adjacent_list, NODE(buffer[0]), array_get(outdegrees, NODE(buffer[0])), NODE(buffer[2]));
      array_increase(indegrees, NODE(buffer[2]));
      array_increase(outdegrees, NODE(buffer[0]));

      array_copy(remaining_indegrees, indegrees);
      deque_clear(zero_indegree_nodes);
      deque_clear(sorted_nodes);
      multiple_ordering = 0;

      for (p = 0; p < n; ++p) {
        if (array_get(remaining_indegrees, p) == 0) {
          deque_push_back(zero_indegree_nodes, p);
        }
      }

      while (deque_size(zero_indegree_nodes) > 0) {
        if (deque_size(zero_indegree_nodes) > 1) {
          multiple_ordering = 1;
        }
        p = deque_pop_back(zero_indegree_nodes);
        deque_push_back(sorted_nodes, p);

        for (j = 0; j < array_get(outdegrees, p); ++j) {
          q = matrix_get(adjacent_list, p, j);
          array_decrease(remaining_indegrees, q);
          if (array_get(remaining_indegrees, q) == 0) {
            deque_push_back(zero_indegree_nodes, q);
          }
        }
      }

      if (deque_size(sorted_nodes) == n) {
        if (!multiple_ordering) {
          printf("Sorted sequence determined after %d relations: ", i + 1);
          while (deque_size(sorted_nodes) > 0) {
            printf("%c", CHAR(deque_pop_front(sorted_nodes)));
          }
          printf(".\n");
          solved = 1;
        }

      } else {
        for (p = 0; p < n; ++p) {
          if (array_get(remaining_indegrees, p) > 0) {
            printf("Inconsistency found after %d relations.\n", i + 1);
            solved = 1;
            break;
          }
        }
      }
    }

    if (!solved) {
      printf("Sorted sequence cannot be determined.\n");
    }
  }

  return 0;
}

// begin: deque module implementation
void deque_clear(deque_t deque) {
  deque->head = 0;
  deque->tail = 0;
}

int deque_size(deque_t deque) {
  if (deque->tail >= deque->head) {
    return deque->tail - deque->head;

  } else {
    return deque->tail - deque->head + deque->capacity;
  }
}

int deque_pop_back(deque_t deque) {
  deque->tail--;
  if (deque->tail < 0) {
    deque->tail = deque->capacity;
  }
  return deque->data[deque->tail];
}

int deque_pop_front(deque_t deque) {
  int value = deque->data[deque->head];
  deque->head++;
  if (deque->head == deque->capacity + 1) {
    deque->head = 0;
  }
  return value;
}

void deque_push_front(deque_t deque, int value) {
  deque->head--;
  if (deque->head < 0) {
    deque->head = deque->capacity;
  }
  deque->data[deque->head] = value;
}

void deque_push_back(deque_t deque, int value) {
  deque->data[deque->tail] = value;
  deque->tail++;
  if (deque->tail == (deque->capacity + 1)) {
    deque->tail = 0;
  }
}

void deque_del(deque_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

deque_t deque_new(int capacity) {
  struct deque_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (capacity + 1));
  ptr->capacity = capacity;
  ptr->head = 0;
  ptr->tail = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}
// end: deque module implementation

// begin: matrix module implementation
void matrix_clear(matrix_t matrix) {
  memset(matrix->data, 0, sizeof(int) * matrix->row * matrix->col);
}

int matrix_get(matrix_t matrix, int row, int col) {
  return matrix->data[matrix->col * row + col];
}

void matrix_set(matrix_t matrix, int row, int col, int value) {
  matrix->data[matrix->col * row + col] = value;
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

// begin: array module implementation
void array_copy(array_t dest, array_t src) {
  int i;
  for (i = 0; i < src->capacity; ++i) {
    dest->data[i] = src->data[i];
  }
}

void array_increase(array_t array, int index) {
  array->data[index]++;
}

void array_decrease(array_t array, int index) {
  array->data[index]--;
}

void array_clear(array_t array) {
  memset(array->data, 0, sizeof(int) * array->capacity);
}

int array_get(array_t array, int index) {
  return array->data[index];
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
  ptr->data = (int *) (ptr + 1);
  memset(ptr->data, 0, sizeof(int) * capacity);
  return ptr;
}
// end: array module implementation
