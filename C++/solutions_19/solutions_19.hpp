#pragma once

#include "../lib/linked_list.hpp"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy = ListNode();
    dummy.next = head;

    ListNode *trailer = &dummy;
    ListNode *leader = &dummy;

    for (int i = 1; i <= n; i++) {
      leader = leader->next;
    }

    while (leader->next != nullptr) {
      trailer = trailer->next;
      leader = leader->next;
    }

    ListNode *next_node = trailer->next;
    trailer->next = next_node->next;
    delete next_node;

    return dummy.next;
  }
};
