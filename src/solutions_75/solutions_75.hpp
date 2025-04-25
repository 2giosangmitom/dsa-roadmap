#pragma once

#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int left = 0, i = 0, right = nums.size() - 1;

    while (i <= right) {
      if (nums[i] == 0) {
        std::swap(nums[i++], nums[left++]);
      } else if (nums[i] == 2) {
        std::swap(nums[i], nums[right--]);
      } else {
        i++;
      }
    }
  }
};
