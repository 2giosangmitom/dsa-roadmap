#include "move_zeroes.hpp"

void Solution::moveZeroes(vector<int> &nums) {
  size_t slow = 0;
  size_t fast = 0;

  while (fast < nums.size()) {
    if (nums[fast] != 0) {
      swap(nums[fast++], nums[slow++]);
    } else {
      fast++;
    }
  }
}