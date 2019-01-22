#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEALTH (1000 + 3)
#define MAX_ARMOR (1000 + (1000 + 16) / 17 * 7)

struct matrix_t {
  int row_count;
  int col_count;
  int * data;
};

typedef struct matrix_t * matrix_t;

matrix_t matrix_make(int row_count, int col_count) {
  struct matrix_t * ptr = malloc(sizeof(*ptr) + sizeof(int) * row_count * col_count);
  ptr->row_count = row_count;
  ptr->col_count = col_count;
  ptr->data = (int *) (ptr + 1);
  memset(ptr->data, -1, sizeof(int) * row_count * col_count);
  return ptr;
}

void matrix_clear(matrix_t matrix) {
  memset(matrix->data, -1, sizeof(int) * matrix->row_count + matrix->col_count);
}

void matrix_set(matrix_t matrix, int row, int col, int value) {
  matrix->data[row * matrix->col_count + col] = value;
}

int matrix_get(matrix_t matrix, int row, int col) {
  return matrix->data[row * matrix->col_count + col];
}

#define NO_WHERE 0
#define IN_WATER 1
#define IN_FIRE 2
#define IN_AIR 3

int dp(matrix_t water, matrix_t fire, matrix_t air, int health, int armor, int where) {
  int i, j;
  if (health <= 0 || armor <= 0) {
    return 0;
  }
  if (where == IN_WATER) {
    i = matrix_get(water, health, armor);
    if (i != -1) {
      return i;
    }
  }
  if (where == IN_FIRE) {
    i = matrix_get(fire, health, armor);
    if (i != -1) {
      return i;
    }
  }
  if (where == IN_AIR) {
    i = matrix_get(air, health, armor);
    if (i != -1) {
      return i;
    }
  }

  i = 0;
  if (where != IN_WATER) {
    j = (where == NO_WHERE ? 0 : 1) + dp(water, fire, air, health - 5, armor - 10, IN_WATER);
    if (i < j) {
      i = j;
    }
  }
  if (where != IN_FIRE) {
    j = (where == NO_WHERE ? 0 : 1) + dp(water, fire, air, health - 20, armor + 5, IN_FIRE);
    if (i < j) {
      i = j;
    }
  }
  if (where != IN_AIR) {
    j = (where == NO_WHERE ? 0 : 1) + dp(water, fire, air, health + 3, armor + 2, IN_AIR);
    if (i < j) {
      i = j;
    }
  }

  if (where == IN_WATER) {
    matrix_set(water, health, armor, i);

  } else if (where == IN_FIRE) {
    matrix_set(fire, health, armor, i);

  } else if (where == IN_AIR) {
    matrix_set(air, health, armor, i);
  }

  return i;
}

int main(int argc, char * argv[]) {
  matrix_t water = matrix_make(MAX_HEALTH + 1, MAX_ARMOR + 1);
  matrix_t fire = matrix_make(MAX_HEALTH + 1, MAX_ARMOR + 1);
  matrix_t air = matrix_make(MAX_HEALTH + 1, MAX_ARMOR + 1);
  int case_count;
  int health;
  int armor;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d", &health, &armor);
    matrix_clear(water);
    matrix_clear(fire);
    matrix_clear(air);
    printf("%d\n", dp(water, fire, air, health, armor, NO_WHERE));
  }
  return 0;
}
