#pragma once

#include <vector>
using std::vector;

class Solution {
   public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n);
        prefix_sum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            int sum_left = i - 1 >= 0 ? prefix_sum[i - 1] : 0;
            int sum_right = i + 1 <= n ? prefix_sum[n - 1] - prefix_sum[i] : 0;

            if (sum_left == sum_right) {
                return i;
            }
        }

        return -1;
    }
};
