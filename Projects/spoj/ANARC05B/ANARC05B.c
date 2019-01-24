#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int size1;
int size2;
int array1[MAX_SIZE];
int array2[MAX_SIZE];
int point1[MAX_SIZE];
int point2[MAX_SIZE];

int state1[MAX_SIZE];
int state2[MAX_SIZE];

int dp1(int i);
int dp2(int i);

int max(int x, int y) {
  return x > y ? x : y;
}

int dp1(int i) {
  int j, k;
  if (i >= size1) {
    return 0;
  }
  if (state1[i] != -1) {
    return state1[i];
  }
  if (point1[i] != -1) {
    j = array1[i] + dp1(i + 1);
    k = array2[point1[i]] + dp2(point1[i] + 1);
    state1[i] = max(j, k);
    return state1[i];

  } else {
    state1[i] = array1[i] + dp1(i + 1);
    return state1[i];
  }
}

int dp2(int i) {
  int j, k;
  if (i >= size2) {
    return 0;
  }
  if (state2[i] != -1) {
    return state2[i];
  }
  if (point2[i] != -1) {
    j = array2[i] + dp2(i + 1);
    k = array1[point2[i]] + dp1(point2[i] + 1);
    state2[i] = max(j, k);
    return state2[i];

  } else {
    state2[i] = array2[i] + dp2(i + 1);
    return state2[i];
  }
}

int input() {
  int i;
  scanf("%d", &size1);
  if (size1 == 0) {
    return 0;
  }
  for (i = 0; i < size1; ++i) {
    scanf("%d", &array1[i]);
  }
  scanf("%d", &size2);
  for (i = 0; i < size2; ++i) {
    scanf("%d", &array2[i]);
  }
  return 1;
}

void init() {
  int i = 0;
  int j = 0;
  memset(point1, -1, sizeof(point1));
  memset(point2, -1, sizeof(point2));
  while (i < size1 && j < size2) {
    if (array1[i] == array2[j]) {
      point1[i] = j;
      point2[j] = i;
      i++;
      j++;

    } else if (array1[i] < array2[j]) {
      i++;

    } else {
      j++;
    }
  }
  memset(state1, -1, sizeof(state1));
  memset(state2, -1, sizeof(state2));
}

int main(int argc, char * argv[]) {
  int i;
  int j;
  while(input()) {
    init();
    i = dp1(0);
    j = dp2(0);
    printf("%d\n", max(i, j));
  }
  return 0;
}
