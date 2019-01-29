#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DECIMAL_DIGIT_COUNT 9
#define BASE 1000000000LL
typedef long long digit_t;

struct number_t {
  int digit_count;
  digit_t * digits;
};
typedef struct number_t * number_t;

digit_t number_make_digit(char * string, int index) {
  int i;
  int j;
  digit_t digit = 0;
  for (i = 0, j = 1; i < DECIMAL_DIGIT_COUNT; ++i, j *= 10) {
    if (string[index + i] == '\0') {
      break;
    } else {
      digit += j * (string[index + i] - '0');
    }
  }
  return digit;
}

number_t number_zero(int digit_count) {
  struct number_t * ptr = malloc(sizeof(*ptr) + sizeof(digit_t) * digit_count);
  ptr->digit_count = digit_count;
  ptr->digits = (digit_t *) (ptr + 1);
  memset(ptr->digits, 0, sizeof(digit_t) * digit_count);
  return ptr;
}

number_t number_make(char * string, int length) {
  int i, j;
  int digit_count = (length + DECIMAL_DIGIT_COUNT - 1) / DECIMAL_DIGIT_COUNT;
  struct number_t * ptr = malloc(sizeof(*ptr) + sizeof(digit_t) * digit_count);
  ptr->digit_count = digit_count;
  ptr->digits = (digit_t *) (ptr + 1);
  for (i = 0; i < digit_count; ++i) {
    ptr->digits[i] = number_make_digit(string, DECIMAL_DIGIT_COUNT * i);
  }
  return ptr;
}

void number_free(number_t * ptr) {
  free(*ptr);
  *ptr = NULL;
}

number_t number_mul(number_t x, number_t y) {
  int i, j;
  digit_t k;
  number_t z = number_zero(x->digit_count + y->digit_count);
  for (i = 0; i < x->digit_count; ++i) {
    for (j = 0, k = 0; j < y->digit_count; ++j) {
      k += x->digits[i] * y->digits[j] + z->digits[i + j];
      z->digits[i + j] = k % BASE;
      k /= BASE;
    }
    for (; j < x->digit_count + y->digit_count - i; ++j) {
      k += z->digits[i + j];
      z->digits[i + j] = k % BASE;
      k /= BASE;
    }
  }
  return z;
}

void number_print(number_t number) {
  int i;
  for (i = number->digit_count - 1; i >= 0 && number->digits[i] == 0; --i);
  if (i < 0) {
    printf("0\n");
    return;
  }
  printf("%lld", number->digits[i]);
  for (--i; i >= 0; --i) {
    printf("%09lld", number->digits[i]);
  }
  printf("\n");
}

void reverse(char * string, int length) {
  int i;
  int j;
  char c;
  for (i = 0, j = length - 1; i < j; ++i, --j) {
    c = string[i];
    string[i] = string[j];
    string[j] = c;
  }
}

char buffer1[10001];
char buffer2[10002];
int len1;
int len2;

void run() {
  number_t x;
  number_t y;
  number_t z;
  scanf("%s%s", buffer1, buffer2);
  len1 = strlen(buffer1);
  len2 = strlen(buffer2);
  reverse(buffer1, len1);
  reverse(buffer2, len2);
  x = number_make(buffer1, len1);
  y = number_make(buffer2, len2);
  z = number_mul(x, y);
  number_print(z);
  number_free(&x);
  number_free(&y);
  number_free(&z);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
