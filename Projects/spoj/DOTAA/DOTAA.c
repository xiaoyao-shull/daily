#include <stdio.h>

int main(int argc, char * argv[]) {
  int case_count;
  int heros;
  int towers;
  int damage;
  int rounds;
  int health;
  scanf("%d", &case_count);
  while (case_count--) {
    scanf("%d%d%d", &heros, &towers, &damage);
    rounds = 0;
    while (heros--) {
      scanf("%d", &health);
      rounds += ((health - 1) / damage);
    }
    printf("%s\n", rounds >= towers ? "YES" : "NO");
  }
  return 0;
}
