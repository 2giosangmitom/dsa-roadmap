#pragma once

#include "../lib/linked_list.hpp"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
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
};
