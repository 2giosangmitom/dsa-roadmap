#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
      return head;
    }

    int len = 0;
    ListNode dummy_head(0, head);
    ListNode* tail = &dummy_head;
    while (tail && tail->next) {
      tail = tail->next;
      len++;
    }

    k %= len;

    if (k != 0) {
      tail = &dummy_head;
      ListNode* prev = &dummy_head;

      for (int i = 1; i <= k; i++) {
        tail = tail->next;
      }

      while (tail->next != nullptr) {
        prev = prev->next;
        tail = tail->next;
      }

      auto new_head = prev->next;
      prev->next = nullptr;
      tail->next = dummy_head.next;
      dummy_head.next = new_head;
    }

    return dummy_head.next;
  }
};
