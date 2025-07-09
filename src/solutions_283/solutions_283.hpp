#pragma once

#include <vector>

using std::vector;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        size_t slow = 0;
        size_t fast = 0;
        size_t n = nums.size();

        while (fast < n) {
            if (nums[fast] != 0) {
                std::swap(nums[fast++], nums[slow++]);
            } else {
                fast++;
            }
        }
    }
};
