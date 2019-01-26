#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------------
int lengthOfLongestSubstring(char * s) {
  int map[256];
  int i, j, k;
  int max_result;
  int new_result;
  if (s[0] == '\0') {
    return 0;
  }
  memset(map, -1, sizeof(map));
  map[s[0]] = 0;
  max_result = 1;

  for (i = 0, j = 1, k = strlen(s); j < k; ++j) {
    if (map[s[j]] == -1 || map[s[j]] < i) {
      new_result = (j - i) + 1;
      if (max_result < new_result) {
        max_result = new_result;
      }
      map[s[j]] = j;

    } else {
      new_result = (j - map[s[j]]);
      if (max_result < new_result) {
        max_result = new_result;
      }
      i = map[s[j]] + 1;
      map[s[j]] = j;
    }
  }
  return max_result;
}
// -----------------------------------------------------------------------------

void test(char * string, int result) {
  printf("%s\n", lengthOfLongestSubstring(string) == result ? "passed" : "failed");
}

int main(int argc, char * argv[]) {
  test("abcabcbb", 3);
  test("bbbbb", 1);
  test("pwwkew", 3);
  test("", 0);
  test("aab", 2);
}
