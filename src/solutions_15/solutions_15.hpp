#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> twoSum(vector<int> &nums, int left, int target) {
    int right = nums.size() - 1;

    vector<vector<int>> result;

    while (left < right) {
      int sum = nums[left] + nums[right];

      if (sum == target) {
        result.push_back({nums[left], nums[right]});

        left++;
        // Ignore duplicates
        while (left < right && nums[left] == nums[left - 1]) {
          left++;
        }
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }

    return result;
  }

public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (size_t i = 0; i < nums.size(); i++) {
      // Optimization: since the array is sorted, we can exit the loop early
      // because it no longer can find any pair.
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int target = -1 * nums[i];
      auto pairs = twoSum(nums, i + 1, target);

      for (auto p : pairs) {
        result.push_back({nums[i], p[0], p[1]});
      }
    }

    return result;
  }
};
