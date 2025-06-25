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

    // Traditional DP
    int maxSubArray2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        size_t n = nums.size();
        vector<int> dp(n);
        int max_sum = dp[0] = nums[0];

        for (size_t i = 1; i < n; i++) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            max_sum = std::max(dp[i], max_sum);
        }

        return max_sum;
    }
};
