#include "../lib/linked_list.h"
#include <string.h>

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *res = NULL;
  int carry = 0;
  struct ListNode *current = res;

  while (l1 != NULL || l2 != NULL || carry > 0) {
    int digit1 = l1 != NULL ? l1->val : 0;
    int digit2 = l2 != NULL ? l2->val : 0;
    int sum = digit1 + digit2 + carry;

    int digit = sum % 10;
    carry = sum / 10;

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = digit;
    new_node->next = NULL;

    if (current == NULL) {
      current = new_node;
      res = current;
    } else {
      current->next = new_node;
      current = current->next;
    }

    l1 = l1 != NULL ? l1->next : NULL;
    l2 = l2 != NULL ? l2->next : NULL;
  }

  return res;
}
