#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  /**
   * @brief Finds the intersection node of two singly linked lists.
   * @param headA Pointer to the head of the first linked list.
   * @param headB Pointer to the head of the second linked list.
   * @return Pointer to the intersection node, or nullptr if there is no intersection.
   */
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr_1 = headA;
    ListNode *ptr_2 = headB;

    // Traverse both lists until the pointers meet or reach the end
    while (ptr_1 != ptr_2) {
      // Move the pointer to the next node, or switch to the other list's head
      ptr_1 = ptr_1 ? ptr_1->next : headB;
      ptr_2 = ptr_2 ? ptr_2->next : headA;
    }

    // Return the intersection node, or nullptr if there is no intersection
    return ptr_1;
  }
};
