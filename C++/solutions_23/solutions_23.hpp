#pragma once

#include "../lib/linked_list.hpp"
#include <cmath>

class Solution {
private:
  void heap_add(vector<ListNode *> &heap, ListNode *val) {
    heap.push_back(val);

    int current = heap.size() - 1;
    int parent = (current - 1) / 2;

    while (current > 0 && heap[parent]->val > heap[current]->val) {
      swap(heap[parent], heap[current]);
      current = parent;
      parent = (current - 1) / 2;
    }
  }

  ListNode *heap_pop(vector<ListNode *> &heap) {
    swap(heap[0], heap.back());
    ListNode *res = heap.back();
    heap.pop_back();

    int parent = 0;

    while (true) {
      int left = 2 * parent + 1;
      int right = 2 * parent + 2;
      int smallest = parent;

      if (left < static_cast<int>(heap.size()) &&
          heap[left]->val < heap[smallest]->val) {
        smallest = left;
      }

      if (right < static_cast<int>(heap.size()) &&
          heap[right]->val < heap[smallest]->val) {
        smallest = right;
      }

      if (smallest == parent)
        break;

      swap(heap[parent], heap[smallest]);
      parent = smallest;
    }

    return res;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode dummy_head = ListNode();
    vector<ListNode *> heap;
    heap.reserve(lists.size());

    for (auto &head : lists) {
      if (head != nullptr) {
        heap_add(heap, head);
      }
    }

    ListNode *current = &dummy_head;
    while (!heap.empty()) {
      auto smallest = heap_pop(heap);
      current->next = smallest;
      current = current->next;

      if (smallest->next != nullptr) {
        heap_add(heap, smallest->next);
      }
    }

    return dummy_head.next;
  }
};
