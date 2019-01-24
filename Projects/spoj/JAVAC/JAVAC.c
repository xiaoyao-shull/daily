#include <stdio.h>
#include <string.h>

int is_upper_case(char c) {
  return c >= 'A' && c <= 'Z';
}

int is_lower_case(char c) {
  return c >= 'a' && c <= 'z';
}

char to_upper_case(char c) {
  return 'A' + (c - 'a');
}

char to_lower_case(char c) {
  return 'a' + (c - 'A');
}

int is_java_identifier(char * buffer) {
  int i;
  int j = strlen(buffer);
  if (is_upper_case(buffer[0])) {
    return 0;
  }
  for (i = 0; i < j; ++i) {
    if (buffer[i] == '_') {
      return 0;
    }
  }
  return 1;
}

int is_cpp_identifier(char * buffer) {
  int i;
  int j = strlen(buffer);
  int k = 0;
  if (buffer[0] == '_') {
    return 0;
  }
  if (buffer[j - 1] == '_') {
    return 0;
  }
  for (i = 0; i < j; ++i) {
    if (is_upper_case(buffer[i])) {
      return 0;
    }
    if (buffer[i] == '_') {
      k++;
      if (k > 1) {
        return 0;
      }

    } else {
      k = 0;
    }
  }
  return 1;
}

void to_java_identifier(char * buffer) {
  int i;
  int j = strlen(buffer);
  for (i = 0; i < j && buffer[i] != '_'; ++i) {
    printf("%c", buffer[i]);
  }
  while (++i < j) {
    printf("%c", to_upper_case(buffer[i++]));
    while (i < j && buffer[i] != '_') {
      printf("%c", buffer[i++]);
    }
  }
  printf("\n");
}

void to_cpp_identifier(char * buffer) {
  int i;
  int j = strlen(buffer);
  for (i = 0; i < j && is_lower_case(buffer[i]); ++i) {
    printf("%c", buffer[i]);
  }
  while (i < j) {
    printf("_%c", to_lower_case(buffer[i++]));
    while (i < j && is_lower_case(buffer[i])) {
      printf("%c", buffer[i++]);
    }
  }
  printf("\n");
}

int main(int argc, char * argv[]) {
  char buffer[128];
  int is_java;
  int is_cpp;
  while (scanf("%s", buffer) > 0) {
    is_java = is_java_identifier(buffer);
    is_cpp = is_cpp_identifier(buffer);
    if (!is_java && !is_cpp) {
      printf("Error!\n");

    } else if (is_java) {
      to_cpp_identifier(buffer);

    } else {
      to_java_identifier(buffer);
    }
  }
  return 0;
}
