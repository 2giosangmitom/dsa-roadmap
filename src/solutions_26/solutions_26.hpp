#pragma once

#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[k] != nums[i]) {
                nums[++k] = nums[i];
            }
        }

        return k + 1;
    }
};
