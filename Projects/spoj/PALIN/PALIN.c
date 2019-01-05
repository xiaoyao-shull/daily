#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1000000
char buffer[MAX_BUFFER + 1];

int is_greater(int length) {
  int i, j, k;
  if (length % 2 == 0) {
    for (i = length / 2 - 1, j = length / 2; i >= 0; --i, ++j) {
      if (buffer[i] == buffer[j]) {
        continue;
      }
      return buffer[i] > buffer[j];
    }
    return 0;

  } else {
    for (i = length / 2 - 1, j = length / 2 + 1; i >= 0; --i, ++j) {
      if (buffer[i] == buffer[j]) {
        continue;
      }
      return buffer[i] > buffer[j];
    }
    return 0;
  }
}

void flip(int length) {
  int i, j;
  for (i = (length - 1) / 2, j = length / 2; i >= 0; --i, ++j) {
    buffer[j] = buffer[i];
  }
}

void strip(int length) {
  int i;
  for (i = 0; i < length; ++i) {
    if (buffer[i] != '0') {
      break;
    }
  }
  if (i == length) {
    buffer[1] = '\0';
    return;

  } else {
    strcpy(&buffer[0], &buffer[i]);
  }
}

void run() {
  int i, j, k;
  int length;
  scanf("%s", buffer);
  length = strlen(buffer);
  strip(length);
  length = strlen(buffer);
  if (is_greater(length)) {
    flip(length);
    printf("%s\n", buffer);

  } else {
      for (i = (length - 1) / 2; i >= 0; --i) {
      if (buffer[i] != '9') {
        break;
      }
    }
    if (i < 0) {
      printf("1");
      for (j = 0; j < (length + 1) - 2; ++j) {
        printf("0");
      }
      printf("1\n");

    } else {
      buffer[i] = buffer[i] + 1;
      for (j = i + 1; j <= (length - 1) / 2; ++j) {
        buffer[j] = '0';
      }
      flip(length);
      printf("%s\n", buffer);
    }
  }
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
