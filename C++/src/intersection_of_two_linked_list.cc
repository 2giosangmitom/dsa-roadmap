#include "intersection_of_two_linked_list.hpp"
#include <unordered_set>

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
  unordered_set<ListNode *> nodes;

  ListNode *current_node_a = headA;
  while (current_node_a) {
    nodes.insert(current_node_a);
    current_node_a = current_node_a->next;
  }

  ListNode *current_node_b = headB;
  while (current_node_b) {
    if (nodes.contains(current_node_b)) {
      return current_node_b;
    }
    current_node_b = current_node_b->next;
  }

  return nullptr;
}

ListNode *Solution::getIntersectionNode2(ListNode *headA, ListNode *headB) {
  ListNode *ptr_1 = headA;
  ListNode *ptr_2 = headB;

  while (ptr_1 != ptr_2) {
    ptr_1 = ptr_1 ? ptr_1->next : headB;
    ptr_2 = ptr_2 ? ptr_2->next : headA;
  }

  return ptr_1;
}
