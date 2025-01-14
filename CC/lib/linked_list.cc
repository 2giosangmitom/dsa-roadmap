#include "linked_list.hpp"
#include <iostream>
#include <sstream>

ListNode::ListNode() : val{0}, next{nullptr} {}

ListNode::ListNode(int val) : val{val}, next{nullptr} {}

ListNode::ListNode(int val, ListNode *next) : val{val}, next{next} {}

ListNode::~ListNode() { delete this->next; }

ListNode *ListNode::from(initializer_list<int> &&values) {
  ListNode *res = nullptr;
  ListNode *head = nullptr;

  for (int val : values) {
    ListNode *new_node = new ListNode(val);
    if (!res) {
      res = new_node;
      head = res;
    } else {
      head->next = new_node;
      head = head->next;
    }
  }

  return res;
}

string ListNode::to_string() const {
  stringstream ss;
  const ListNode *current = this;

  while (current) {
    ss << current->val;
    if (current->next) {
      ss << " -> ";
    }
    current = current->next;
  }

  return ss.str();
}
