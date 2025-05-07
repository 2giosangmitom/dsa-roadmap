#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Finds two numbers in the input vector that add up to the target.
   * @param nums Vector of integers.
   * @param target The target sum.
   * @return A vector containing the indices of the two numbers that add up to the target.
   */
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (size_t i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];

      // Check if the complement exists in the map
      if (map.find(complement) != map.end()) {
        return {map[complement], static_cast<int>(i)};
      }

      // Insert the current number and its index into the map
      map.insert({nums[i], i});
    }

    // Return an empty vector if no solution is found
    return {};
  }
};
