#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 400
#define ASSOCIATION_LEFT 1
#define ASSOCIATION_RIGHT 2

char input[MAX_LENGTH + 1];
char output[MAX_LENGTH + 1];
char stack[MAX_LENGTH + 1];
int stack_size;
int output_size;

int association(char operator) {
  if (operator == '^') {
    return ASSOCIATION_RIGHT;

  } else { // if operator is +, -, *, /
    return ASSOCIATION_LEFT;
  }
}

int precedence(char operator) {
  if (operator == '^') {
    return 3;

  } else if (operator == '*' || operator == '/') {
    return 2;

  } else { // if operator is +, -
    return 1;
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  int i, j;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%s", input);
    output_size = 0;
    stack_size = 0;
    for (i = 0, j = strlen(input); i < j; ++i) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        output[output_size] = input[i];
        output_size++;
        continue;
      }
      if (input[i] == '(') {
        stack[stack_size] = input[i];
        stack_size++;
        continue;
      }
      if (input[i] == ')') {
        while (stack_size > 0) {
          if (stack[stack_size - 1] == '(') {
            stack_size--;
            break;

          } else {
            output[output_size] = stack[stack_size - 1];
            output_size++;
            stack_size--;
          }
        }
        continue;
      }

      while (stack[stack_size - 1] != '(' && (precedence(stack[stack_size - 1]) > precedence(input[i]) || (precedence(stack[stack_size - 1]) == precedence(input[i]) && association(stack[stack_size - 1]) == ASSOCIATION_LEFT))) {
        output[output_size] = stack[stack_size - 1];
        output_size++;
        stack_size--;
      }
      stack[stack_size] = input[i];
      stack_size++;
    }
    output[output_size] = '\0';
    printf("%s\n", output);
  }
  return 0;
}
