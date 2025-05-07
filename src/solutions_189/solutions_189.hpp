#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Rotates the elements of the input vector to the right by k steps.
   * @param nums Vector of integers to be rotated.
   * @param k Number of steps to rotate the vector.
   */
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();

    if (k != 0) {
      // Reverse the entire vector
      reverse(nums.begin(), nums.end());
      // Reverse the first k elements
      reverse(nums.begin(), nums.begin() + k);
      // Reverse the remaining elements
      reverse(nums.begin() + k, nums.end());
    }
  }
};
