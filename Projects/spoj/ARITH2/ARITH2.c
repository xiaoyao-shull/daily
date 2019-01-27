#include <stdio.h>

long long to_long_long(char * string) {
  long long result = 0;
  while (*string) {
    result *= 10LL;
    result += (long long) (*string - '0');
    string++;
  }
  return result;
}

long long operate(long long x, long long y, char op) {
  switch(op) {
  case '+':
    return x + y;

  case '-':
    return x - y;

  case '*':
    return x * y;

  case '/':
  default:
    return x / y;
  }
}

int main(int argc, char * argv[]) {
  char r1[32];
  char r2[32];
  char op[32];
  int case_count;
  long long result;
  scanf("%d", &case_count);
  while (case_count--) {
    result = 0;
    scanf("%s%s%s", r1, op, r2);
    result = operate(to_long_long(r1), to_long_long(r2), op[0]);
    while (1) {
      scanf("%s", op);
      if (op[0] == '=') {
        printf("%lld\n", result);
        break;

      } else {
        scanf("%s", r1);
        result = operate(result, to_long_long(r1), op[0]);
      }
    }
  }
  return 0;
}
