#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 5000

char buffer[MAX_BUFFER + 1];
long status[MAX_BUFFER + 1];

long dp(int len) {
  if (status[len] != -1) {
    return status[len];
  }
  char x = buffer[len - 2];
  char y = buffer[len - 1];
  status[len] = 0;
  if (y != '0') {
    status[len] += dp(len - 1);
  }
  if ((x == '1') || (x == '2' && y <= '6')) {
    status[len] += dp(len - 2);
  }
  return status[len];
}

int main(int argc, char * argv[]) {
  while (1) {
    scanf("%s", buffer);
    if (buffer[0] == '0') {
      break;
    }
    memset(status, -1, sizeof(status));
    status[0] = 1L;
    status[1] = 1L;
    printf("%ld\n", dp(strlen(buffer)));
  }
  return 0;
}
