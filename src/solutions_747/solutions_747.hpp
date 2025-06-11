#pragma once

#include <vector>
using namespace std;

class Solution {
   public:
    int dominantIndex(vector<int> &nums) {
        int max_i = 0;
        int second_max = -1;

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[max_i]) {
                second_max = nums[max_i];
                max_i = i;
            } else {
                if (nums[i] > second_max) second_max = nums[i];
            }
        }

        return nums[max_i] >= second_max * 2 ? max_i : -1;
    }
};
