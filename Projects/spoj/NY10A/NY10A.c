#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
  int case_count;
  int case_index;
  int count[8];
  char buffer[41];
  int i, x, y, z, h;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d", &case_index);
    scanf("%s", buffer);
    memset(count, 0, sizeof(count));
    for (i = 0; i < 38; ++i) {
      x = buffer[i] == 'T' ? 0 : 4;
      y = buffer[i + 1] == 'T' ? 0 : 2;
      z = buffer[i + 2] == 'T' ? 0 : 1;
      h = x + y + z;
      count[h]++;
    }
    printf("%d", case_index);
    for (i = 0; i < 8; ++i) {
      printf(" %d", count[i]);
    }
    printf("\n");
  }
}
