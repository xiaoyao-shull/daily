#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// -----------------------------------------------------------------------------
struct ListNode *makeListNode(int val) {
  struct ListNode *ptr = malloc(sizeof(*ptr));
  ptr->val = val;
  ptr->next = NULL;
  return ptr;
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *result = makeListNode(0);
  struct ListNode *i = l1;
  struct ListNode *j = l2;
  struct ListNode *k = result;
  int carry = 0;
  int sum;

  while (i != NULL || j != NULL) {
    if (i != NULL && j != NULL) {
      sum = i->val + j->val + carry;
      carry = sum / 10;
      k->next = makeListNode(sum % 10);
      i = i->next;
      j = j->next;
      k = k->next;

    } else if (i != NULL) {
      sum = i->val + carry;
      carry = sum / 10;
      k->next = makeListNode(sum % 10);
      k = k->next;
      i = i->next;

    } else {
      sum = j->val + carry;
      carry = sum / 10;
      k->next = makeListNode(sum % 10);
      k = k->next;
      j = j->next;
    }
  }
  if (carry > 0) {
    k->next = makeListNode(carry);
  }

  k = result;
  result = result->next;
  free(k);
  return result;
}
// -----------------------------------------------------------------------------

int main(int argc, char * argv[]) {
  return 0;
}
