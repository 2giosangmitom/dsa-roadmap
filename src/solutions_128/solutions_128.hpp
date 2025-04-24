#pragma once

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> nums_set(nums.begin(), nums.end());
    int longest_chain = 0;

    for (int num : nums_set) {
      if (!nums_set.contains(num - 1)) {
        int current = num;
        int current_chain = 1;

        while (nums_set.contains(current + 1)) {
          current++;
          current_chain++;
        }

        longest_chain = max(current_chain, longest_chain);
      }
    }

    return longest_chain;
  }
};
