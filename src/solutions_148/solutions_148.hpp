#pragma once

#include "../lib/linked_list.hpp"

class Solution {
 public:
  /**
   * @brief Merge sort for linked list
   * @param head Pointer to the head of the linked list
   * @return Pointer to the head of the sorted linked list
   */
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;

    ListNode *middle = split(head);
    ListNode *left_head = sortList(head);
    ListNode *right_head = sortList(middle);
    return merge(left_head, right_head);
  }

  /**
   * @brief Insertion sort for linked list (TLE)
   * @param head Pointer to the head of the linked list
   * @return Pointer to the head of the sorted linked list
   */
  ListNode *sortList2(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode dummy(0);

    while (head) {
      ListNode *curr = head;
      head = head->next;

      // Find insertion position
      ListNode *prev = &dummy;
      while (prev->next && prev->next->val < curr->val) {
        prev = prev->next;
      }

      // Insert curr after prev
      curr->next = prev->next;
      prev->next = curr;
    }

    return dummy.next;
  }

 private:
  /**
   * @brief Splits the linked list into two halves
   * @param head Pointer to the head of the linked list
   * @return Pointer to the head of the second half of the linked list
   */
  ListNode *split(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *res = slow->next;
    slow->next = nullptr;

    return res;
  }

  /**
   * @brief Merges two sorted linked lists into one sorted linked list
   * @param a Pointer to the head of the first sorted linked list
   * @param b Pointer to the head of the second sorted linked list
   * @return Pointer to the head of the merged sorted linked list
   */
  ListNode *merge(ListNode *a, ListNode *b) {
    ListNode res = ListNode();
    ListNode *curr_res = &res;

    while (a && b) {
      if (a->val <= b->val) {
        curr_res->next = a;
        a = a->next;
      } else {
        curr_res->next = b;
        b = b->next;
      }
      curr_res = curr_res->next;
    }

    curr_res->next = a ? a : b;

    return res.next;
  }
};
