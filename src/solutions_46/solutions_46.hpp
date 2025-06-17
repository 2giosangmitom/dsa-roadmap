#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    void solve(const vector<int>& nums, vector<bool>& used,
               vector<int>& candidate, vector<vector<int>>& result) {
        if (candidate.size() == nums.size()) {
            result.push_back(candidate);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            candidate.push_back(nums[i]);
            used[i] = true;
            solve(nums, used, candidate, result);
            used[i] = false;
            candidate.pop_back();
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(6, false);
        vector<int> candidate;
        vector<vector<int>> result;

        solve(nums, used, candidate, result);

        return result;
    }
};
