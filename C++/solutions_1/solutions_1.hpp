#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (size_t i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];

      if (map.find(complement) != map.end()) {
        return {map[complement], static_cast<int>(i)};
      }

      map.insert({nums[i], i});
    }

    return {};
  }
};
