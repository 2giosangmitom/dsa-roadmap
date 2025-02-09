#include "linked_list.hpp"
#include <sstream>

// ==========================
// Constructors
// ==========================

// Default constructor: initializes value to 0 and next pointer to nullptr
ListNode::ListNode() : val{0}, next{nullptr} {}

// Constructor: initializes the node with a given value
ListNode::ListNode(int val) : val{val}, next{nullptr} {}

// Constructor: initializes the node with a given value and next pointer
ListNode::ListNode(int val, ListNode *next) : val{val}, next{next} {}

// ==========================
// Free memory for linked list
// ==========================
void free_list(ListNode *head) {
  ListNode *current = head;
  ListNode *next;

  while (current) {
    next = current->next; // Store next node before deleting current
    delete current;       // Free current node
    current = next;       // Move to next node
  }
}

// ==========================
// Create a linked list from vector
// ==========================
ListNode *ListNode::from(const vector<int> &nums) {
  if (nums.empty())
    return nullptr; // Return nullptr for empty input

  ListNode *head = nullptr;    // Head of linked list
  ListNode *current = nullptr; // Pointer to track current node

  for (auto it = nums.begin(); it != nums.end(); it++) {
    if (!head) {
      // Initialize head for the first element
      head = new ListNode(*it);
      current = head;
    } else {
      // Create new node and link it to the current list
      current->next = new ListNode(*it);
      current = current->next;
    }
  }

  return head;
}

// ==========================
// Overload equality operator (==)
// ==========================
bool operator==(const ListNode &lhs, const ListNode &rhs) {
  const ListNode *cur1 = &lhs, *cur2 = &rhs;

  while (cur1 && cur2) {
    if (cur1->val != cur2->val) // Compare values of nodes
      return false;
    cur1 = cur1->next; // Move to next node
    cur2 = cur2->next;
  }

  // Both lists must be exhausted at the same time to be equal
  return cur1 == nullptr && cur2 == nullptr;
}

// ==========================
// Convert linked list to string representation
// ==========================
string ListNode::to_string() const {
  stringstream ss;
  const ListNode *current = this;

  while (current) {
    ss << current->val; // Append node value
    if (current->next) {
      ss << " -> "; // Add separator if not the last node
    }
    current = current->next;
  }

  return ss.str();
}

// ==========================
// Overload output stream operator (<<)
// ==========================
ostream &operator<<(ostream &os, ListNode *head) {
  if (head) {
    os << head->to_string(); // Print list using to_string()
  } else {
    os << "Empty"; // Handle case where list is nullptr
  }
  return os;
}
