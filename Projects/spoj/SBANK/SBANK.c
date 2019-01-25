#include <stdio.h>

struct code_t {
  long long hi;
  long long lo;
};
typedef struct code_t code_t;

code_t code_encode(int a, int b, int c, int d, int e, int f) {
  long long hi = 0LL;
  long long lo = 0LL;

  hi += (long long) a;
  hi *= 100000000LL;
  hi += (long long) b;

  lo += (long long) c;
  lo *= 10000LL;
  lo += (long long) d;
  lo *= 10000LL;
  lo += (long long) e;
  lo *= 10000LL;
  lo += (long long) f;

  code_t code;
  code.hi = hi;
  code.lo = lo;
  return code;
}

void code_print(code_t code) {
  long long a = code.hi / 100000000LL;
  long long b = code.hi % 100000000LL;
  long long c = code.lo / 1000000000000LL;
  long long d = code.lo % 1000000000000LL / 100000000LL;
  long long e = code.lo % 100000000LL / 10000LL;
  long long f = code.lo % 10000LL;
  printf("%02lld %08lld %04lld %04lld %04lld %04lld", a, b, c, d, e, f);
}

#define MAX_SIZE 100000
code_t codes[MAX_SIZE];

int code_less(code_t x, code_t y) {
  if (x.hi < y.hi) {
    return 1;
  }
  if (x.hi > y.hi) {
    return 0;
  }
  return x.lo < y.lo;
}

int code_equals(code_t x, code_t y) {
  return x.hi == y.hi && x.lo == y.lo;
}

int quick_sort_partition(code_t * codes, int lower, int upper) {
  code_t pivot = codes[(lower + upper) / 2];
  int i = lower - 1;
  int j = upper + 1;
  code_t temp;
  while (1) {
    do { i++; } while (code_less(codes[i], pivot));
    do { j--; } while (code_less(pivot, codes[j]));
    if (i >= j) {
      return j;
    }
    temp = codes[i];
    codes[i] = codes[j];
    codes[j] = temp;
  }
}

void quick_sort(code_t * codes, int lower, int upper) {
  if (lower >= upper) {
    return;
  }
  int inter = quick_sort_partition(codes, lower, upper);
  quick_sort(codes, lower, inter);
  quick_sort(codes, inter + 1, upper);
}

void run() {
  int size;
  int i, j, k;
  int a, b, c, d, e, f;
  scanf("%d", &size);
  for (i = 0; i < size; ++i) {
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    codes[i] = code_encode(a, b, c, d, e, f);
  }
  quick_sort(codes, 0, size - 1);
  for (i = 0; i < size; ++i) {
    for (j = i + 1; j < size; ++j) {
      if (!code_equals(codes[i], codes[j])) {
        break;
      }
    }
    k = j - i;
    i += (k - 1);
    code_print(codes[i]);
    printf(" %d\n", k);
  }
  printf("\n");
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
