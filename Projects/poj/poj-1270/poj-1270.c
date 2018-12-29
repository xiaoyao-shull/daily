#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// begin: array module
typedef struct array_t {
  int capacity;
  int * data;
} * array_t;

array_t array_new(int capacity) {
  struct array_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * capacity);
  ptr->capacity = capacity;
  ptr->data = (int *) (ptr + 1);
  memset(ptr->data, 0, sizeof(int) * capacity);
  return ptr;
}

void array_del(array_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void array_set(array_t array, int index, int value) {
  array->data[index] = value;
}

int array_get(array_t array, int index) {
  return array->data[index];
}

void array_clear(array_t array) {
  memset(array->data, 0, sizeof(int) * array->capacity);
}

void array_increase(array_t array, int index) {
  array->data[index]++;
}

void array_decrease(array_t array, int index) {
  array->data[index]--;
}

void array_bubble_sort(array_t array, int size) {
  int i;
  int tmp;
  int new_size;
  while (size > 0) {
    new_size = 0;
    for (i = 1; i < size; ++i) {
      if (array->data[i - 1] > array->data[i]) {
        tmp = array->data[i - 1];
        array->data[i - 1] = array->data[i];
        array->data[i] = tmp;
        new_size = i;
      }
    }
    size = new_size;
  }
}
// end: array module

// begin: matrix module
typedef struct matrix_t {
  int row;
  int col;
  int * data;
} * matrix_t;

matrix_t matrix_new(int row, int col) {
  struct matrix_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * row * col);
  ptr->row = row;
  ptr->col = col;
  ptr->data = (int *) (ptr + 1);
  memset(ptr->data, 0, sizeof(int) * row * col);
  return ptr;
}

void matrix_del(matrix_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void matrix_set(matrix_t matrix, int row, int col, int value) {
  matrix->data[row * matrix->col + col] = value;
}

int matrix_get(matrix_t matrix, int row, int col) {
  return matrix->data[row * matrix->col + col];
}

void matrix_clear(matrix_t matrix) {
  memset(matrix->data, 0, sizeof(int) * matrix->row * matrix->col);
}
// end: matrix module

// begin: deque module
typedef struct deque_t {
  int capacity;
  int head;
  int tail;
  int * data;

} * deque_t;

deque_t deque_new(int capacity) {
  struct deque_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (capacity + 1));
  ptr->capacity = capacity;
  ptr->head = 0;
  ptr->tail = 0;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}

void deque_del(deque_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void deque_push_back(deque_t deque, int value) {
  deque->data[deque->tail] = value;
  deque->tail++;
  if (deque->tail == (deque->capacity + 1)) {
    deque->tail = 0;
  }
}

void deque_push_front(deque_t deque, int value) {
  deque->head--;
  if (deque->head < 0) {
    deque->head = (deque->capacity + 1) - 1;
  }
  deque->data[deque->head] = value;
}

int deque_pop_back(deque_t deque) {
  deque->tail--;
  if (deque->tail < 0) {
    deque->tail = (deque->capacity + 1) - 1;
  }
  return deque->data[deque->tail];
}

int deque_pop_front(deque_t deque) {
  int value = deque->data[deque->head];
  deque->head++;
  if (deque->head == (deque->capacity + 1)) {
    deque->head = 0;
  }
  return value;
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

int deque_get(deque_t deque, int index) {
  index += deque->head;
  if (index >= (deque->capacity + 1)) {
    index -= (deque->capacity + 1);
  }
  return deque->data[index];
}
// end: deque module

// begin: heap module
typedef int (*heap_less_t)(int, int);
typedef struct heap_t {
  int capacity;
  int size;
  heap_less_t less;
  int * data;

} * heap_t;

heap_t heap_new(int capacity, heap_less_t less) {
  struct heap_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * (capacity + 1));
  ptr->capacity = capacity;
  ptr->size = 0;
  ptr->less = less;
  ptr->data = (int *) (ptr + 1);
  return ptr;
}

void heap_del(heap_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

void heap_clear(heap_t heap) {
  heap->size = 0;
}

void heap_down(heap_t heap, int index) {
  int tmp;
  int min = index;
  int left = index * 2;
  int right = index * 2 + 1;
  if (left <= heap->size && heap->less(heap->data[left], heap->data[min])) {
    min = left;
  }
  if (right <= heap->size && heap->less(heap->data[right], heap->data[min])) {
    min = right;
  }
  if (min != index) {
    tmp = heap->data[min];
    heap->data[min] = heap->data[index];
    heap->data[index] = tmp;
    heap_down(heap, min);
  }
}

void heap_up(heap_t heap, int index) {
  int parent = index / 2;
  int tmp;
  if (parent <= 0) {
    return;
  }
  if (heap->less(heap->data[index], heap->data[parent])) {
    tmp = heap->data[parent];
    heap->data[parent] = heap->data[index];
    heap->data[index] = tmp;
    heap_up(heap, parent);
  }
}

void heap_push(heap_t heap, int value) {
  heap->size++;
  heap->data[heap->size] = value;
  heap_up(heap, heap->size);
}

int heap_pop(heap_t heap) {
  int value = heap->data[1];
  heap->data[1] = heap->data[heap->size];
  heap->size--;
  heap_down(heap, 1);
  return value;
}

int heap_size(heap_t heap) {
  return heap->size;
}
// end: heap module

#define MAX_EDGE_COUNT 300
#define MAX_NODE_COUNT 20

matrix_t adjacent_matrix;
array_t indegrees;
int node_count;
deque_t ordered_nodes;


char buffer[1024];
array_t characters;
int char_to_node[26];
int node_to_char[MAX_NODE_COUNT + 1];

void init() {
  characters = array_new(26);
  adjacent_matrix = matrix_new(MAX_NODE_COUNT + 1, MAX_NODE_COUNT + 1);
  indegrees = array_new(MAX_NODE_COUNT + 1);
  ordered_nodes = deque_new(MAX_NODE_COUNT);
  node_count = 0;
}

void clear() {
  matrix_clear(adjacent_matrix);
  deque_clear(ordered_nodes);
  array_clear(indegrees);
  node_count = 0;
}

int solved() {
  int i;
  for (i = 1; i <= node_count; ++i) {
    if (array_get(indegrees, i) == 0) {
      return 0;
    }
  }
  return 1;
}

int solve() {
  int i, j;
  if (solved()) {
    if (deque_size(ordered_nodes) == node_count) {
      for (i = 0; i < node_count; ++i) {
        printf("%c%s", node_to_char[deque_get(ordered_nodes, i)], (i == node_count - 1) ? "\n" : "");
      }
      return 1;

    } else {
      return 0;
    }
  }

  for (i = 1; i <= node_count; ++i) {
    if (array_get(indegrees, i) == 0) {
      deque_push_back(ordered_nodes, i);
      array_set(indegrees, i, -1);
      for (j = 1; j <= node_count; ++j) {
        if (matrix_get(adjacent_matrix, i, j)) {
          array_decrease(indegrees, j);
        }
      }
      if (!solve()) {
        return 0;
      }
      for (j = 1; j <= node_count; ++j) {
        if (matrix_get(adjacent_matrix, i, j)) {
          array_increase(indegrees, j);
        }
      }
      array_set(indegrees, i, 0);
      deque_pop_back(ordered_nodes);
    }
  }
  return 1;
}

int is_letter(char c) {
  return c >= 'a' && c <= 'z';
}

/*
 * 按字典序输出所有拓扑序.
 * 注意字典序与输入字符的顺序无关.
 */
int main(int argc, char * argv[]) {
  int i, j, k, u, v;
  init();
  while (fgets(buffer, 1024, stdin) != NULL) {
    clear();
    for (i = 0, j = strlen(buffer); i < j; ++i) {
      if (is_letter(buffer[i])) {
        array_set(characters, node_count, buffer[i]);
        node_count++;
      }
    }
    array_bubble_sort(characters, node_count);
    for (i = 0; i < node_count; ++i) {
      j = array_get(characters, i);
      node_to_char[i + 1] = (char) j;
      char_to_node[j - 'a'] = i + 1;
    }
    fgets(buffer, 1024, stdin);
    i = 0;
    j = 1;
    k = strlen(buffer);
    while (i < k && j < k) {
      if (!is_letter(buffer[i])) {
        i++;
        j++;
        continue;
      }
      if (!is_letter(buffer[j])) {
        j++;
        continue;
      }
      u = char_to_node[buffer[i] - 'a'];
      v = char_to_node[buffer[j] - 'a'];
      i = j + 1;
      j = i + 1;
      if (matrix_get(adjacent_matrix, u, v)) {
        continue;
      }
      matrix_set(adjacent_matrix, u, v, 1);
      array_increase(indegrees, v);
    }
    solve();
    printf("\n");
  }
  return 0;
}
