#include "two_sum.hpp"
#include <unordered_map>

vector<int> Solution::twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hash_table;

  for (size_t i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (hash_table.count(complement)) {
      return {hash_table[complement], static_cast<int>(i)};
    }
    hash_table.insert({nums[i], i});
  }

  return {};
}
