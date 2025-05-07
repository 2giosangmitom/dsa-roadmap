#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  /**
   * @brief Removes all elements with a given value from the linked list.
   * @param head Pointer to the head of the linked list.
   * @param val The value to be removed from the linked list.
   * @return Pointer to the head of the modified linked list.
   */
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0, head);
    ListNode* curr = &dummy;

    // Traverse the linked list
    while (curr && curr->next) {
      // If the next node's value matches the target value, remove it
      if (curr->next->val == val) {
        auto next_node = curr->next->next;
        delete curr->next;
        curr->next = next_node;
        continue;
      }
      curr = curr->next;
    }

    return dummy.next;
  }
};
