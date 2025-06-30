#pragma once

#include <vector>
using std::vector;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int destination = n - 1;

        for (int i = destination; i >= 0; i--) {
            if (i + nums[i] >= destination) {
                destination = i;
            }
        }

        return destination == 0;
    }
};
