#pragma once

#include <ostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
  // Fields
  int val;
  ListNode *next;

  // Constructors
  ListNode();
  ListNode(int x);
  ListNode(int x, ListNode *next);

  // Create a linked list from a list
  // Return nullptr if enter empty list
  static ListNode *from(const vector<int> &nums);

  // Represent the linked list in string
  string to_string() const;
};

// Overload ostream operator
ostream &operator<<(ostream &os, ListNode *head);

// Overload equality operator
bool operator==(const ListNode &lhs, const ListNode &rhs);

// Free dynamically allocated memory for linked list
void free_list(ListNode *head);
