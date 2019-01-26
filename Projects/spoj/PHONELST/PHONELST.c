#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TRIE_ALPHABET_SIZE 10

struct trie_t {
  int terminating;
  int with_children;
  struct trie_t * characters[TRIE_ALPHABET_SIZE];
};

typedef struct trie_t * trie_t;

trie_t trie_make() {
  struct trie_t * ptr = malloc(sizeof(*ptr));
  ptr->terminating = 0;
  ptr->with_children = 0;
  memset(ptr->characters, 0, sizeof(ptr->characters));
  return ptr;
}

void trie_free(trie_t * ptr) {
  int i;
  for (i = 0; i < TRIE_ALPHABET_SIZE; ++i) {
    if ((*ptr)->characters[i] != NULL) {
      trie_free(&(*ptr)->characters[i]);
    }
  }
  free(*ptr);
  *ptr = NULL;
}

void trie_insert(trie_t trie, char * string) {
  while (*string) {
    if (trie->characters[*string - '0'] == NULL) {
      trie->characters[*string - '0'] = trie_make();
    }
    trie->with_children = 1;
    trie = trie->characters[*string - '0'];
    string++;
  }
  trie->terminating = 1;
}

int check(trie_t trie) {
  int i;
  if (trie->terminating && trie->with_children) {
    return 0;
  }
  for (i = 0; i < TRIE_ALPHABET_SIZE; ++i) {
    if (trie->characters[i] == NULL) {
      continue;
    }
    if (check(trie->characters[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

void run() {
  int number_count;
  char number[11];
  trie_t trie = trie_make();
  scanf("%d", &number_count);
  while (number_count--) {
    scanf("%s", number);
    trie_insert(trie, number);
  }
  if (check(trie) == 0) {
    printf("NO\n");

  } else {
    printf("YES\n");
  }
  trie_free(&trie);
}

int main(int argc, char * argv[]) {
  int case_count;
  scanf("%d", &case_count);
  while (case_count--) {
    run();
  }
  return 0;
}
