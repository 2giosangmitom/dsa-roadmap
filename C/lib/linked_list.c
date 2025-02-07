#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a singly linked list from an array
struct ListNode *create_list(int *values, int values_c) {
  if (values_c <= 0) {
    return NULL;
  }

  struct ListNode *head = NULL;
  for (int i = values_c - 1; i >= 0; i--) {
    struct ListNode *new_node =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!new_node) {
      free_list(head);
      return NULL;
    }

    new_node->val = values[i];
    new_node->next = head;
    head = new_node;
  }

  return head;
}

// Represent a linked list in string
char *list_to_str(struct ListNode *head) {
  if (!head) {
    return strdup("Empty list");
  }

  size_t length = 1;
  struct ListNode *curr = head;

  while (curr) {
    length += snprintf(NULL, 0, "%d", curr->val);
    if (curr->next) {
      length += 4; // Space for " -> "
    }
    curr = curr->next;
  }

  char *res = (char *)malloc(length);
  if (!res) {
    return NULL;
  }

  curr = head;
  char *ptr = res;
  size_t remaining = length;

  while (curr) {
    int written = snprintf(ptr, remaining, "%d", curr->val);
    ptr += written;
    remaining -= written;

    if (curr->next) {
      written = snprintf(ptr, remaining, " -> ");
      ptr += written;
      remaining -= written;
    }
    curr = curr->next;
  }

  return res;
}

// Release all allocated memories
void free_list(struct ListNode *head) {
  struct ListNode *current = head;
  while (current) {
    struct ListNode *next = current->next;
    free(current);
    current = next;
  }
}
