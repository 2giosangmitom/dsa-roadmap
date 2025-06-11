#pragma once

#include <vector>
using namespace std;

class NumArray {
   private:
    vector<int> prefix_sum;

   public:
    NumArray(vector<int> &nums) {
        prefix_sum.resize(nums.size());
        prefix_sum[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix_sum[right] - (left - 1 >= 0 ? prefix_sum[left - 1] : 0);
    }
};
