#pragma once

#include "../lib/linked_list.hpp"

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
};
