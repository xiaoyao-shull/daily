#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_friend[10000];
int is_friend_of_friend[10000];

int main(int argc, char * argv[]) {
  int friend_count;
  int i;
  int j;
  int friend;
  int friend_of_friend_count;
  int friend_of_friend;
  memset(is_friend, 0, sizeof(is_friend));
  memset(is_friend_of_friend, 0, sizeof(is_friend_of_friend));
  scanf("%d", &friend_count);
  while (friend_count--) {
    scanf("%d", &friend);
    is_friend[friend] = 1;
    is_friend_of_friend[friend] = 0;
    scanf("%d", &friend_of_friend_count);
    for (i = 0; i < friend_of_friend_count; ++i) {
      scanf("%d", &friend_of_friend);
      if (!is_friend[friend_of_friend]) {
        is_friend_of_friend[friend_of_friend] = 1;
      }
    }
  }
  for (i = 0, j = 0; i < 10000; ++i) {
    if (is_friend_of_friend[i]) {
      j++;
    }
  }
  printf("%d\n", j);
  return 0;
}
