#pragma once

#include <initializer_list>
#include <vector>

// Struct represent a singly linked list
struct ListNode {
  int val;
  ListNode *next;

  // Constructors
  ListNode();
  ListNode(int val);
  ListNode(int val, ListNode *next);
};

// Check equality of two linked list
bool list_equal(ListNode *l1, ListNode *l2);

// Create a linked list from an array
ListNode *create_list(const std::vector<int> &values);

// Delete a list of linked list
void delete_list(const std::initializer_list<ListNode *> &lists);

// Convert a linked list to a vector
std::vector<int> list_to_vector(ListNode *head);