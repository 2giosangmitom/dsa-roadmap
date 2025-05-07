#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Counts the number of good pairs in the input vector.
   * @param nums Vector of integers.
   * @return The number of good pairs.
   */
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> freq;
    int result = 0;

    for (int n : nums) {
      // If the number already exists in the map, increment the result by the frequency of the number
      if (freq.contains(n)) {
        result += freq[n]++;
      } else {
        // Otherwise, add the number to the map with a frequency of 1
        freq[n] = 1;
      }
    }

    return result;
  }
};
