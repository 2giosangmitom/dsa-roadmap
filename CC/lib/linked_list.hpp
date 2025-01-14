#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <initializer_list>
#include <string>
using namespace std;

// Node in a singly linked list
struct ListNode {
  int val;
  ListNode *next;

  // Constructors
  explicit ListNode();
  explicit ListNode(int val);
  explicit ListNode(int val, ListNode *next);
  ~ListNode();

  // Create a linked list from a list of values
  static ListNode *from(initializer_list<int> &&values);

  // Convert the list to a string (e.g., "1 -> 2 -> 3")
  string to_string() const;
};

#endif // LINKED_LIST_HPP
