#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Finds two numbers in the input vector that add up to the target.
   * @param numbers Vector of integers.
   * @param target The target sum.
   * @return A vector containing the indices of the two numbers that add up to the target.
   */
  vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
      int sum = numbers[left] + numbers[right];

      // Check if the sum of the two numbers is equal to the target
      if (sum == target) {
        return {left + 1, right + 1};
      }

      // If the sum is less than the target, move the left pointer to the right
      if (sum < target) {
        left++;
      } else {
        // If the sum is greater than the target, move the right pointer to the left
        right--;
      }
    }

    // Return an empty vector if no solution is found
    return {};
  }
};
