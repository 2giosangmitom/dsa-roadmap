#pragma once

#include <vector>

class Solution {
 private:
  void solve(const std::vector<int>& nums, size_t i, std::vector<int> subset,
             std::vector<std::vector<int>>& result) {
    if (i == nums.size()) {
      result.push_back(subset);
      return;
    }

    solve(nums, i + 1, subset, result);
    subset.push_back(nums[i]);
    solve(nums, i + 1, subset, result);
  }

 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    solve(nums, 0, {}, result);

    return result;
  }
};