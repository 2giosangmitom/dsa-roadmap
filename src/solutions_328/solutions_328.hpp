#pragma once

#include "../lib/linked_list.hpp"

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = even_head;

        return head;
    }
};
