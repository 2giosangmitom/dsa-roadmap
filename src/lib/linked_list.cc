#include "linked_list.hpp"
#include <string>

// Constructors
ListNode::ListNode() : val{0}, next{nullptr} {}
ListNode::ListNode(int val) : val{val}, next{nullptr} {}
ListNode::ListNode(int val, ListNode *next) : val{val}, next{next} {}

// Destructor
ListNode::~ListNode() { delete next; }

// Factory function to create linked list
ListNode *make_list(const vector<int> &list) {
  ListNode *head = nullptr;
  ListNode *current = head;

  for (const int &val : list) {
    auto new_node = new ListNode(val);
    if (current == nullptr) {
      head = new_node;
      current = new_node;
    } else {
      current->next = new_node;
      current = new_node;
    }
  }

  return head;
}

// Overload equality operator
bool operator==(const ListNode &lhs, const ListNode &rhs) {
  auto currentA = &lhs;
  auto currentB = &rhs;

  while (currentA != nullptr && currentB != nullptr) {
    if (currentA->val != currentB->val) {
      return false;
    }
    currentA = currentA->next;
    currentB = currentB->next;
  }

  return currentA == currentB;
}

// Overload to_string function
string to_string(const ListNode &list) {
  string result;

  for (auto head = &list; head != nullptr; head = head->next) {
    result = result.append(to_string(head->val));
    if (head->next) {
      result = result.append(" -> ");
    }
  }

  return result;
};
