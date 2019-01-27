#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 16

int is_parlindrome(char * string) {
  int i = 0;
  int j = strlen(string) - 1;
  while (i < j) {
    if (string[i] != string[j]) {
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}

int main(int argc, char * argv[]) {
  int case_count;
  char buffer[MAX_BUFFER];
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%s", buffer);
    printf("%s\n", is_parlindrome(buffer) ? "YES" : "NO");
  }
  return 0;
}
