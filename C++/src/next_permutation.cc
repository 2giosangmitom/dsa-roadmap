#include "next_permutation.hpp"
#include <algorithm>

void Solution::nextPermutation(vector<int> &nums) {
  size_t left = nums.size() - 2;

  while (int(left) >= 0 && nums[left] >= nums[left + 1]) {
    left--;
  }

  // If left is -1, it mean the current state is the last permutation
  if (int(left) == -1) {
    reverse(nums.begin(), nums.end());
  } else {
    size_t right = nums.size() - 1;
    while (nums[right] <= nums[left]) {
      right--;
    }

    swap(nums[left], nums[right]);

    reverse(nums.begin() + long(left) + 1, nums.end());
  }
}