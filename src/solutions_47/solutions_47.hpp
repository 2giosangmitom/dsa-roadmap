#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 private:
  void helper(const vector<int>& nums, vector<bool>& used,
              vector<int>& candidate, vector<vector<int>>& result) {
    if (candidate.size() == nums.size()) {
      result.push_back(candidate);
      return;
    }

    size_t n = nums.size();
    for (size_t i = 0; i < n; i++) {
      if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
        continue;
      }
      used[i] = true;
      candidate.push_back(nums[i]);
      helper(nums, used, candidate, result);
      candidate.pop_back();
      used[i] = false;
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<int> candidate;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    helper(nums, used, candidate, result);
    return result;
  }
};
