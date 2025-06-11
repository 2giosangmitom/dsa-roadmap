#pragma once

#include "../lib/linked_list.hpp"

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr_1 = headA;
        ListNode *ptr_2 = headB;

        while (ptr_1 != ptr_2) {
            ptr_1 = ptr_1 ? ptr_1->next : headB;
            ptr_2 = ptr_2 ? ptr_2->next : headA;
        }

        return ptr_1;
    }
};
