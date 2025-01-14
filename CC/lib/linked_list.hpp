#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <initializer_list>
#include <string>
using namespace std;

// Represents a node in a singly linked list.
struct ListNode {
  int val;
  ListNode *next;

  // Default constructor that initializes the node with a value of 0 and
  // a null pointer.
  ListNode();

  // Constructor that initializes the node with a specified value
  ListNode(int val);

  // Constructor that initializes the node with a specified value and a next
  // node
  ListNode(int val, ListNode *next);

  // Destructor that releases all nodes in the linked list starting from the
  // current node.
  ~ListNode();

  // Creates a linked list from an initializer list of integers.
  static ListNode *from(initializer_list<int> values);

  // Converts the linked list to a string representation.
  string to_string();
};

#endif // !LINKED_LIST_HPP
