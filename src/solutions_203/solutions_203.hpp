#pragma once

#include "../lib/linked_list.hpp"

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode* curr = &dummy;

        while (curr && curr->next) {
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
