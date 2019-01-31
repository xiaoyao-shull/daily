#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int x, int y) {
  return x < y ? x : y;
}

int main(int argc, char * argv[]) {
  char word1[MAX_LENGTH + 1];
  char word2[MAX_LENGTH + 1];
  int freq1[26];
  int freq2[26];
  char common[MAX_LENGTH + 1];
  int i, j, k;
  while (scanf("%s%s", word1, word2) > 0) {
    memset(freq1, 0, sizeof(freq1));
    memset(freq2, 0, sizeof(freq2));
    for (i = 0, j = strlen(word1); i < j; ++i) {
      freq1[word1[i] - 'a']++;
    }
    for (i = 0, j = strlen(word2); i < j; ++i) {
      freq2[word2[i] - 'a']++;
    }
    for (i = 0; i < 26; ++i) {
      j = min(freq1[i], freq2[i]);
      while (j--) {
        printf("%c", 'a' + i);
      }
    }
    printf("\n");
  }
  return 0;
}
