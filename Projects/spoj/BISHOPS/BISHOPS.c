#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 101

void flip(char * string) {
  int i = 0;
  int j = strlen(string) - 1;
  char c;
  while (i < j) {
    c = string[i];
    string[i] = string[j];
    string[j] = c;
    i++;
    j--;
  }
}

void strip(char * string) {
  int j = strlen(string) - 1;
  while (string[j] == '0') {
    string[j] = '\0';
    j--;
  }
}

int main(int argc, char * argv[]) {
  char buffer[MAX_LENGTH + 1 + 1] = { 0 };
  int p;
  int i, j, k;
  while (scanf("%s", buffer) > 0) {
    if (strlen(buffer) == 1 && buffer[0] == '1') {
      printf("1\n");
      continue;
    }
    flip(buffer);
    for (i = 0, j = strlen(buffer), k = 0; i < j; ++i) {
      p = (buffer[i] - '0') * 2 + k;
      buffer[i] = '0' + (p % 10);
      k = p / 10;
    }
    if (k != 0) {
      buffer[i] = '0' + k;
    }
    if (buffer[0] >= '2') {
      buffer[0] -= 2;

    } else {
      buffer[0] -= 2;
      buffer[0] += 10;
      for (i = 1, j = strlen(buffer), k = 1; i < j; ++i) {
        p = (buffer[i] - '0') - k;
        if (p < 0) {
          p += 10;
          k = 1;

        } else {
          k = 0;
        }
        buffer[i] = p + '0';
      }
    }
    strip(buffer);
    flip(buffer);
    printf("%s\n", buffer);
    memset(buffer, 0, sizeof(buffer));
  }
  return 0;
}
