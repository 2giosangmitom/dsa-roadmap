#pragma once

#include <initializer_list>
#include <string>
#include <vector>

// Definition for a linked list node
struct ListNode {
  int val;
  ListNode *next;

  // Constructors
  ListNode();
  ListNode(int val);
  ListNode(int val, ListNode *next);

  // Represent list in string
  std::string to_string() const;
};

// Factory function to create linked list
ListNode *make_list(const std::vector<int> &list);

// Overload equality operator
bool operator==(const ListNode &lhs, const ListNode &rhs);

// Release dynamic allocated memory for linked list
void delete_list(std::initializer_list<ListNode *> heads);

// Overload output operator
std::ostream &operator<<(std::ostream &os, ListNode *head);
