#pragma once

#include <algorithm>
#include <cmath>

#include "../lib/linked_list.hpp"

class Solution {
 public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };

    ListNode dummy_head = ListNode();

    std::vector<ListNode *> heap;
    heap.reserve(lists.size());
    for (auto &list : lists) {
      if (list != nullptr) {
        heap.push_back(list);
      }
    }

    std::make_heap(heap.begin(), heap.end(), comp);

    ListNode *current = &dummy_head;
    while (!heap.empty()) {
      auto smallest = heap.front();
      std::pop_heap(heap.begin(), heap.end(), comp);
      heap.pop_back();
      current->next = smallest;
      current = current->next;

      if (smallest->next != nullptr) {
        std::push_heap(heap.begin(), heap.end(), comp);
        heap.push_back(smallest->next);
      }
    }

    return dummy_head.next;
  }
};
