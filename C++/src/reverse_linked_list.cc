#include "reverse_linked_list.hpp"

ListNode *Solution::reverseList(ListNode *head) {
  ListNode *current = head;
  ListNode *prev = nullptr;

  while (current) {
    ListNode *nextNode = current->next;
    current->next = prev;
    prev = current;
    current = nextNode;
  }

  return prev;
}
