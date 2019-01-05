#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 200

int main(int argc, char * argv[]) {
  int row, col;
  int i, j;
  char buffer[MAX_BUFFER + 1];
  while (scanf("%d", &col), col > 0) {
    scanf("%s", buffer);
    row = strlen(buffer) / col;

    for (j = 0; j < col; ++j) {
      for (i = 0; i < row; ++i) {
        if (i % 2 == 0) {
          printf("%c", buffer[i * col + j]);
        } else {
          printf("%c", buffer[(i + 1) * col - (j + 1)]);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
