#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

// Create a singly linked list from an array
// Returns the head pointer of the list if values_c > 0
// Returns NULL if values_c <= 0
struct ListNode *create_list(int *values, int values_c) {
  if (values_c <= 0) {
    return NULL;
  }

  struct ListNode *head = NULL;
  for (int i = values_c - 1; i >= 0; i--) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = values[i];
    new_node->next = head;
    head = new_node;
  }

  return head;
}

// Release all allocated memories
void free_list(struct ListNode *head) {
  struct ListNode *current = head;
  struct ListNode *next = NULL;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
}