#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val{0}, next{nullptr} {}
  ListNode(int val) : val{val}, next{nullptr} {}
  ListNode(int val, ListNode *next) : val{val}, next{next} {}
};

#endif // !LINKED_LIST_HPP
