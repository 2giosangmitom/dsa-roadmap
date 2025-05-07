#pragma once

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Finds the length of the longest consecutive elements sequence in an unsorted array.
   * @param nums Vector of integers.
   * @return The length of the longest consecutive elements sequence.
   */
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> nums_set(nums.begin(), nums.end());
    int longest_chain = 0;

    for (int num : nums_set) {
      // Check if the current number is the start of a sequence
      if (!nums_set.contains(num - 1)) {
        int current = num;
        int current_chain = 1;

        // Count the length of the current sequence
        while (nums_set.contains(current + 1)) {
          current++;
          current_chain++;
        }

        // Update the longest chain if the current sequence is longer
        longest_chain = max(current_chain, longest_chain);
      }
    }

    return longest_chain;
  }
};
