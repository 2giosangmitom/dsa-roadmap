#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy = ListNode();
    dummy.next = head;

    ListNode *trailer = &dummy;
    ListNode *leader = &dummy;

    // Move leader n steps ahead
    for (int i = 1; i <= n; i++) {
      if (leader == nullptr) return nullptr;  // Avoid out-of-bound errors
      leader = leader->next;
    }

    // Move both leader and trailer until leader reaches the end
    while (leader->next != nullptr) {
      trailer = trailer->next;
      leader = leader->next;
    }

    if (leader == head) {
      return nullptr;
    }

    ListNode *next_node = trailer->next;
    trailer->next = next_node->next;
    delete next_node;

    // Save the result before deleting dummy
    ListNode *result = dummy.next;

    return result;
  }
};
