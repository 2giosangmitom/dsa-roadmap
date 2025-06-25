#pragma once

#include <vector>

using std::vector;

class Solution {
   public:
    // Kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int max_sum = -10000;  // Minimum of input
        int current_sum = max_sum;

        for (const int& num : nums) {
            current_sum = std::max(current_sum + num, num);
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum;
    }
};
