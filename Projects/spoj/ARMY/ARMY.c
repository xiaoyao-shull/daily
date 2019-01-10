#include <stdio.h>

void run() {
  int nx, ny;
  int mx, my;
  int i;
  int n;
  scanf("%d%d", &nx, &ny);
  for (i = 0; i < nx; ++i) {
    scanf("%d", &n);
    if (i == 0 || mx < n) {
      mx = n;
    }
  }
  for (i = 0; i < ny; ++i) {
    scanf("%d", &n);
    if (i == 0 || my < n) {
      my = n;
    }
  }
  printf("%s\n", mx >= my ? "Godzilla" : "MechaGodzilla");
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
