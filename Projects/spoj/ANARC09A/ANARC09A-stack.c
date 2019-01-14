#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 2000

int main(int argc, char * argv[]) {
  int stack;
  int count;
  int i, j;
  int case_index = 0;
  char buffer[MAX_BUFFER + 1];
  while (1) {
    scanf("%s", buffer);
    if (buffer[0] == '-') {
      break;
    }
    case_index++;
    stack = 0;
    count = 0;
    for (i = 0, j = strlen(buffer); i < j; ++i) {
      if (buffer[i] == '{') {
        stack++;

      } else {
        if (stack > 0) {
          stack--;

        } else {
          stack++;
          count++;
        }
      }
    }
    printf("%d. %d\n", case_index, count + stack / 2);
  }
}
