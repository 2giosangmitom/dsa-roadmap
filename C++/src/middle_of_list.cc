#include "middle_of_list.hpp"

ListNode *Solution::middleNode(ListNode *head) {
  ListNode *slow = head, *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}
