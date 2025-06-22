#pragma once

#include <vector>
using std::vector;

class Solution {
   public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (size_t i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};
