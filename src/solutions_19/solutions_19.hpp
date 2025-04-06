#pragma once

#include "../lib/linked_list.hpp"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *trailer = dummy;
    ListNode *leader = dummy;

    // Move leader n steps ahead
    for (int i = 1; i <= n; i++) {
      if (leader == nullptr)
        return nullptr; // Avoid out-of-bound errors
      leader = leader->next;
    }

    // Move both leader and trailer until leader reaches the end
    while (leader->next != nullptr) {
      trailer = trailer->next;
      leader = leader->next;
    }

    if (leader == head) {
      dummy->next = nullptr;
      delete dummy;
      return nullptr;
    }

    ListNode *next_node = trailer->next;
    trailer->next = next_node->next;

    // Safely disconnect next_node before deleting
    next_node->next = nullptr;
    delete next_node;

    // Save the result before deleting dummy
    ListNode *result = dummy->next;

    dummy->next = nullptr;
    delete dummy;

    return result;
  }
};
