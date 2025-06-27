#pragma once

#include <cstdint>
#include <vector>
using std::vector;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int n = nums.size();

        vector<int> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        int i = 0, j = 0;

        while (j < n) {
            int sum = prefix_sum[j] - (i - 1 < 0 ? 0 : prefix_sum[i - 1]);

            if (sum == target) {
                result = std::min(result, static_cast<int>(j - i + 1));
                i++;
                j++;
            } else if (sum < target) {
                j++;
            } else {
                result = std::min(result, static_cast<int>(j - i + 1));
                i++;
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};
