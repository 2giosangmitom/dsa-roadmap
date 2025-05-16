#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  // Swap nodes
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy_head(0, head);
    ListNode* prev = &dummy_head;
    ListNode* curr = head;

    while (curr && curr->next) {
      prev->next = curr->next;
      curr->next = curr->next->next;
      prev->next->next = curr;

      prev = curr;
      curr = curr->next;
    }

    return dummy_head.next;
  }

  // Just swap values
  ListNode* swapPairs2(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* prev = head;
    ListNode* next = head->next;

    while (next != nullptr) {
      std::swap(prev->val, next->val);
      prev = prev->next ? prev->next->next : nullptr;
      next = next->next ? next->next->next : nullptr;
    }

    return head;
  }
};
