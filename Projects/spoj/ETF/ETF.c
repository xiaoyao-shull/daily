#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  int mark[1000001];
  int func[1000001];
  int i, j;
  memset(mark, 0, sizeof(mark));
  for (i = 1; i <= 1000000; ++i) {
    func[i] = i;
  }
  for (i = 2; i <= 1000; ++i) {
    for (j = i * 2; j <= 1000000; j += i) {
      mark[j] = 1;
    }
  }
  for (i = 2; i <= 1000000; ++i) {
    if (mark[i] == 1) {
      continue;
    }
    for (j = i; j <= 1000000; j += i) {
      func[j] = func[j] / i * (i - 1) ;
    }
  }
  scanf("%d", &i);
  while (i--) {
    scanf("%d", &j);
    printf("%d\n", func[j]);
  }
  return 0;
}
