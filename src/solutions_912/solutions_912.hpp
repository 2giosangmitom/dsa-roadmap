#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  // Heap sort (if you don't want to implement a heap) :)
  vector<int> sortArray(vector<int> &nums) {
    make_heap(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 1; i++) {
      pop_heap(nums.begin(), nums.end() - i);
    }

    return nums;
  }
};
