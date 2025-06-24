#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
   private:
    int solve(vector<int>& nums, int target, int i, int n,
              unordered_map<std::string, int>& memo) {
        if (i == n) {
            return target == 0 ? 1 : 0;
        }

        auto key = std::to_string(i) + "-" + std::to_string(target);
        if (memo.contains(key)) {
            return memo[key];
        }

        memo[key] = solve(nums, target - nums[i], i + 1, n, memo) +
                    solve(nums, target + nums[i], i + 1, n, memo);

        return memo[key];
    }

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<std::string, int> memo;
        return solve(nums, target, 0, nums.size(), memo);
    }
};
