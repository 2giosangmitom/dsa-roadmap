#pragma once

#include <unordered_map>
#include <vector>

class Solution {
   public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> seen;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            auto it = seen.find(nums[i]);
            if (it != seen.end() && i - it->second <= k) {
                return true;
            }
            seen[nums[i]] = i;
        }

        return false;
    }
};
