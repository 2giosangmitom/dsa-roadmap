#pragma once

#include "../lib/linked_list.hpp"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
