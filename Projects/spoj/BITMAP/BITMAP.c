#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point_t {
  int row;
  int col;

} point_t;

#define MAX_ROW_COUNT 182
#define MAX_COL_COUNT 182

int distances[MAX_ROW_COUNT * MAX_COL_COUNT];

void set_distance(int row, int col, int distance) {
  distances[row * MAX_COL_COUNT + col] = distance;
}

int get_distance(int row, int col) {
  return distances[row * MAX_COL_COUNT + col];
}

void clear_distances() {
  memset(distances, -1, sizeof(int) * MAX_ROW_COUNT * MAX_COL_COUNT);
}

#ifndef __DEQUE_MODULE_INCLUDED__
#define __DEQUE_MODULE_INCLUDED__
#define item_t point_t

struct deque_t {
  int capacity;
  int head;
  int tail;
  item_t * items;
};

typedef struct deque_t * deque_t;

deque_t deque_make(int capacity) {
  struct deque_t * ptr = malloc(sizeof(*ptr) + sizeof(item_t) * (capacity + 1));
  ptr->capacity = capacity;
  ptr->head = 0;
  ptr->tail = 0;
  ptr->items = (item_t *) (ptr + 1);
  return ptr;
}

void deque_free(deque_t * ptr) {
  free(*ptr);
  *ptr = NULL;
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

void deque_push_back(deque_t deque, item_t item) {
  deque->items[deque->tail] = item;
  deque->tail++;
  if (deque->tail == (deque->capacity + 1)) {
    deque->tail = 0;
  }
}

item_t deque_pop_front(deque_t deque) {
  item_t item = deque->items[deque->head];
  deque->head++;
  if (deque->head == (deque->capacity + 1)) {
    deque->head = 0;
  }
  return item;
}

#undef item_t
#endif // __DEQUE_MODULE_INCLUDED__

deque_t deque;
int row_delta[4] = { -1, 0, 1, 0 };
int col_delta[4] = { 0, -1, 0, 1 };

void run() {
  int row, col;
  int row_count, col_count;
  char buffer[MAX_COL_COUNT + 1];
  point_t p, q;
  int i, j, k;
  scanf("%d%d", &row_count, &col_count);
  deque_clear(deque);
  clear_distances();
  for (row = 0; row < row_count; ++row) {
    scanf("%s", buffer);
    for (col = 0; col < col_count; ++col) {
      if (buffer[col] == '1') {
        p.row = row;
        p.col = col;
        deque_push_back(deque, p);
        set_distance(row, col, 0);
      }
    }
  }
  while (deque_size(deque) > 0) {
    for (i = 0, j = deque_size(deque); i < j; ++i) {
      p = deque_pop_front(deque);
      for (k = 0; k < 4; ++k) {
        row = p.row + row_delta[k];
        col = p.col + col_delta[k];
        if (row < 0 || col < 0 || row >= row_count || col >= col_count) {
          continue;
        }
        if (get_distance(row, col) != -1) {
          continue;
        }
        set_distance(row, col, get_distance(p.row, p.col) + 1);
        q.row = row;
        q.col = col;
        deque_push_back(deque, q);
      }
    }
  }
  for (row = 0; row < row_count; ++row) {
    for (col = 0; col < col_count; ++col) {
      printf("%d%s", get_distance(row, col), col == col_count - 1 ? "\n" : " ");
    }
  }
}

void init() {
  deque = deque_make(MAX_ROW_COUNT * MAX_COL_COUNT);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  init();
  while (case_count--) {
    run();
  }
  return 0;
}
