#pragma once

#include "../lib/linked_list.hpp"

class Solution {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy_head(0);
        int carry = 0;
        ListNode *curr = &dummy_head;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *new_node = new ListNode(digit);
            curr->next = new_node;
            curr = curr->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummy_head.next;
    }
};
