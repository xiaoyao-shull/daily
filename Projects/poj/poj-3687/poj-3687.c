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


#define MAX_NODE_COUNT 200
#define MAX_EDGE_COUNT 40000

matrix_t adjacent_matrix;
deque_t ordered_nodes;
heap_t zero_outdegree_nodes;
array_t outdegrees;
array_t output_buffer;
int node_count;
int edge_count;

int less(int i, int j) {
  return i > j;
}

void init() {
  adjacent_matrix = matrix_new(MAX_NODE_COUNT + 1, MAX_NODE_COUNT + 1);
  ordered_nodes = deque_new(MAX_NODE_COUNT);
  zero_outdegree_nodes = heap_new(MAX_NODE_COUNT, less);
  outdegrees = array_new(MAX_NODE_COUNT + 1);
  output_buffer = array_new(MAX_NODE_COUNT);
}

void clear() {
  matrix_clear(adjacent_matrix);
  deque_clear(ordered_nodes);
  heap_clear(zero_outdegree_nodes);
  array_clear(outdegrees);
}

void run() {
  int i, j, k;
  scanf("%d%d", &node_count, &edge_count);
  clear();
  for (i = 0; i < edge_count; ++i) {
    scanf("%d%d", &j, &k);
    if (matrix_get(adjacent_matrix, j, k)) {
      continue;
    }
    matrix_set(adjacent_matrix, j, k, 1);
    array_increase(outdegrees, j);
  }

  for (i = 1; i <= node_count; ++i) {
    if (array_get(outdegrees, i) == 0) {
      heap_push(zero_outdegree_nodes, i);
    }
  }

  while (heap_size(zero_outdegree_nodes) > 0) {
    i = heap_pop(zero_outdegree_nodes);
    deque_push_front(ordered_nodes, i);
    for (j = 1; j <= node_count; ++j) {
      if (matrix_get(adjacent_matrix, j, i) > 0) {
        array_decrease(outdegrees, j);
        if (array_get(outdegrees, j) == 0) {
          heap_push(zero_outdegree_nodes, j);
        }
      }
    }
  }

  if (deque_size(ordered_nodes) < node_count) {
    printf("-1\n");
    return;
  }

  for (i = 0; i < deque_size(ordered_nodes); ++i) {
    j = deque_get(ordered_nodes, i);
    array_set(output_buffer, j - 1, i + 1);
  }
  for (i = 0; i < node_count; ++i) {
    printf("%d%s", array_get(output_buffer, i), (i == node_count - 1) ? "\n" : " ");
  }
}

/*
 * 这个题目看起来是个平淡无奇的拓扑排序，但要做对需要一些观察和技巧.
 *
 * 先整理下题意：
 * 1. 有小球 1 到 n，小球重量与其编号相同.
 * 2. 给各个小球贴标签，标签分别为 1 到 n.
 * 3. 根据所贴标签小球的轻重关系，约束了标签的拓扑序.
 * 4. 按标签从小到大的顺序输出小球重量，要求输出的序列字典序最小.
 *
 * 由于约束了标签之间的关系，所以可以很容易求出标签的拓扑序.
 * 拓扑序不唯一，所以需要观察标签的拓扑序与小球重量序列的对应关系.
 * 要让小球重量序列的字典序最小，在标签的拓扑序中，应该首先让标签 1 尽可能靠前，然后让标签 2 尽可能靠前，以此类推.
 * 需要注意，标签的这种顺序并不是字典序.
 * Kahn 算法虽然无法得出满足这种条件的拓扑序，但是具有相似的性质（注：使用极小堆维护入度为零的点集）.
 * 通过观察伪代码发现，Kahn 算法会让标签 n 尽可能靠后，然后让标签 n - 1 尽可能靠后，以此类推.
 *
 * 对 Kahn 算法进行改造，得到反向 Kahn 算法：
 * 1. 入度为零的点集改为出度为零的点集.
 * 2. 每次从出度为零的点集中选取编号最大的点，加入拓扑序列的前端.
 *
 * 反向 Kahn 算法也可以得到拓扑序，并且拓扑序具有这道题目所需要的性质.
 * 网上很多讨论，将解法概括为“反向建图，逆序输出”，但很少对原理进行解释，其实这与反向 Kahn 算法是等效的.
 */
int main(int argc, char * argv[]) {
  init();
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
