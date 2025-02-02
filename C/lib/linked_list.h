#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

// Create a singly linked list from an array
// Returns the head pointer of the list if values_c > 0
// Returns NULL if values_c <= 0
struct ListNode *create_list(int *values, int values_c);

// Release all allocated memories
void free_list(struct ListNode *head);

#endif // LINKED_LIST_H
