#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int left = 0;

    for (size_t right = 0; right < nums.size(); right++) {
      if (nums[right] != val) {
        nums[left++] = nums[right];
      }
    }

    return left;
  }
};
