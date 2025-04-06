#pragma once

#include <memory>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  // Constructors
  ListNode();
  ListNode(int val);
  ListNode(int val, ListNode *next);

  // Destructor
  ~ListNode();
};

// Factory function to create linked list
unique_ptr<ListNode> make_list(const vector<int> &list);

// Overload equality operator
bool operator==(const ListNode &lhs, const ListNode &rhs);

// Overload to_string function
string to_string(const ListNode &list);
