#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 2048

char buffer[MAX_BUFFER];

int is_lower_letter(char c) {
  return c >= 'a' && c <= 'z';
}

int is_upper_letter(char c) {
  return c >= 'A' && c <= 'Z';
}

int is_letter(char c) {
  return is_lower_letter(c) || is_upper_letter(c);
}

char to_lower(char c) {
  if (is_lower_letter(c)) {
    return c;
  } else {
    return c + 32;
  }
}

int run() {
  char c = to_lower(buffer[0]);
  int i = 0;
  while (1) {
    while (is_letter(buffer[i])) {
      i++;
    }
    while (buffer[i] != '\0' && !is_letter(buffer[i])) {
      i++;
    }
    if (buffer[i] == '\0') {
      return 1;
    }
    if (to_lower(buffer[i]) != c) {
      return 0;
    }
  }
}

int main(int argc, char * argv[]) {
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    if (strlen(buffer) == 2 && buffer[0] == '*') {
      break;
    }
    printf("%s\n", run() == 1 ? "Y" : "N");
  }
  return 0;
}
