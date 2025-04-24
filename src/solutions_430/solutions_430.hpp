#pragma once

// Definition for a Node.
class Node {
 public:
  int val;
  Node *prev;
  Node *next;
  Node *child;

  Node(int v) : val{v}, prev{nullptr}, next{nullptr}, child{nullptr} {}
  Node(int v, Node *p, Node *n, Node *c) : val{v}, prev{p}, next{n}, child{c} {}
};

class Solution {
 public:
  Node *flatten(Node *head) {
    Node *current = head;

    while (current != nullptr) {
      if (current->child != nullptr) {
        Node *next = current->next;

        current->next = current->child;
        current->child->prev = current;

        // Find the tail of the child node
        Node *child_node = current->child;
        while (child_node->next != nullptr) {
          child_node = child_node->next;
        }
        child_node->next = next;

        if (next != nullptr) next->prev = child_node;

        current->child = nullptr;
      }
      current = current->next;
    }

    return head;
  }
};