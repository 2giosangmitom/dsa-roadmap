#pragma once

#include "../lib/linked_list.hpp"

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *middle = split(head);
    ListNode *left_head = sortList(head);
    ListNode *right_head = sortList(middle);
    return merge(left_head, right_head);
  }

private:
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
