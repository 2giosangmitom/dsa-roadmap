#include "3sum.hpp"
#include <algorithm>

vector<vector<int>> ThreeSum::Solution::twoSum(int left, vector<int> &nums,
                                               int target) {
  int right = nums.size() - 1;
  vector<vector<int>> res;

  while (left < right) {
    int sum = nums[left] + nums[right];

    if (sum == target) {
      res.push_back({nums[left], nums[right]});
      left++;
      while (left < right && nums[left - 1] == nums[left]) {
        left++;
      }
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  return res;
}

vector<vector<int>> ThreeSum::Solution::threeSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  vector<vector<int>> res;

  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      break;
    }
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    auto pairs = twoSum(i + 1, nums, -nums[i]);

    for (auto pair : pairs) {
      res.push_back({nums[i], pair[0], pair[1]});
    }
  }

  return res;
}
