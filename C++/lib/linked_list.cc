#include "linked_list.hpp"

#include <sstream>

ListNode::ListNode() : val{0}, next{nullptr} {}
ListNode::ListNode(int val) : val{val}, next{nullptr} {}
ListNode::ListNode(int val, ListNode *next) : val{val}, next{next} {}

// Free dynamically allocated memory for linked list
void free_list(ListNode *head) {
  ListNode *current = head;
  ListNode *next;

  while (current) {
    next = current->next;  // Store next node before deleting current
    delete current;        // Free current node
    current = next;        // Move to next node
  }
}

// Create a linked list from vector
ListNode *ListNode::from(const vector<int> &nums) {
  if (nums.empty()) return nullptr;  // Return nullptr for empty input

  ListNode *head = nullptr;     // Head of linked list
  ListNode *current = nullptr;  // Pointer to track current node

  for (int num : nums) {
    if (!head) {
      // Initialize head for the first element
      head = new ListNode(num);
      current = head;
    } else {
      // Create new node and link it to the current list
      current->next = new ListNode(num);
      current = current->next;
    }
  }

  return head;
}

// Overload equality operator
bool operator==(const ListNode &lhs, const ListNode &rhs) {
  const ListNode *cur1 = &lhs, *cur2 = &rhs;

  while (cur1 && cur2) {
    if (cur1->val != cur2->val) return false;
    cur1 = cur1->next;
    cur2 = cur2->next;
  }

  // Both lists must be exhausted at the same time to be equal
  return cur1 == nullptr && cur2 == nullptr;
}

// Represent the linked list in string
string ListNode::to_string() const {
  stringstream ss;
  const ListNode *current = this;

  while (current != nullptr) {
    ss << current->val;
    if (current->next) {
      ss << " -> ";
    }
    current = current->next;
  }

  return ss.str();
}

// Overload ostream operator
ostream &operator<<(ostream &os, ListNode *head) {
  if (head != nullptr) {
    os << head->to_string();
  } else {
    os << "Empty";
  }
  return os;
}
