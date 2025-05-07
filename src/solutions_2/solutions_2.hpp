#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  /**
   * @brief Adds two numbers represented by linked lists.
   * @param l1 Pointer to the head of the first linked list.
   * @param l2 Pointer to the head of the second linked list.
   * @return Pointer to the head of the resulting linked list.
   */
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = nullptr;
    int carry = 0;
    ListNode *head = res;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      // Get the values of the current digits
      int digit1 = l1 ? l1->val : 0;
      int digit2 = l2 ? l2->val : 0;

      // Calculate the sum and the carry
      int sum = digit1 + digit2 + carry;
      int digit = sum % 10;
      carry = sum / 10;

      // Create a new node with the calculated digit
      ListNode *new_node = new ListNode(digit);
      if (!head) {
        res = new_node;
        head = res;
      } else {
        head->next = new_node;
        head = head->next;
      }

      // Move to the next nodes in the lists
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }

    return res;
  }
};
