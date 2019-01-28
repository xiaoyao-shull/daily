#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_SIZE 100000

int run(int n, int k) {
  std::vector<int> array(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &array[i]);
  }
  std::sort(array.begin(), array.end());

  int answer = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && array[j] - array[i] < k) {
      j++;
    }
    if (j >= n) {
      break;
    }
    if (array[j] - array[i] == k) {
      answer++;
    }
  }
  return answer;
}

int main(int argc, char * argv[]) {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d\n", run(n, k));
  return 0;
}
