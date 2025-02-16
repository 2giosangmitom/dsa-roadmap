#include "palindrome_linked_list.hpp"

ListNode *Solution::find_mid(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode *Solution::reverse(ListNode *head) {
  ListNode *prev_node = nullptr;
  ListNode *current_node = head;

  while (current_node) {
    ListNode *next_node = current_node->next;
    current_node->next = prev_node;
    prev_node = current_node;
    current_node = next_node;
  }

  return prev_node;
}

bool Solution::isPalindrome(ListNode *head) {
  ListNode *mid = find_mid(head);
  ListNode *reversed = reverse(mid);

  ListNode *ptr_2 = reversed;
  ListNode *ptr_1 = head;

  while (ptr_2) {
    if (ptr_1->val != ptr_2->val) {
      return false;
    }
    ptr_1 = ptr_1->next;
    ptr_2 = ptr_2->next;
  }

  // Normalize the list for release memory
  ptr_1 = head;
  if (ptr_1->next) {
    while (ptr_1->next->next) {
      ptr_1 = ptr_1->next;
    }
    ptr_1->next = reversed;
  }

  return true;
}
