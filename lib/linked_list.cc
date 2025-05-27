#include "linked_list.hh"
#include <iterator>

// Constructors
ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int val) : val(val), next(nullptr) {}
ListNode::ListNode(int val, ListNode *next) : val(val), next(next) {}

// Check equality of two linked list
bool list_equal(ListNode *l1, ListNode *l2) {
  while (l1 && l2) {
    if (l1->val != l2->val) {
      return false;
    }
    l1 = l1->next;
    l2 = l2->next;
  }
  return l1 == nullptr && l2 == nullptr;
}

// Create a linked list from an array
ListNode *create_list(const std::vector<int> &values) {
  if (values.size() == 0) {
    return nullptr;
  }

  ListNode *head = new ListNode(*values.begin());
  ListNode *current = head;

  for (auto it = std::next(values.begin()); it != values.end(); ++it) {
    current->next = new ListNode(*it);
    current = current->next;
  }

  return head;
}

// Delete a list of linked list
void delete_list(const std::initializer_list<ListNode *> &lists) {
  for (ListNode *list : lists) {
    while (list) {
      ListNode *temp = list;
      list = list->next;
      delete temp;
    }
  }
}

// Convert a linked list to a vector
std::vector<int> list_to_vector(ListNode *head) {
  std::vector<int> result;
  while (head) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}