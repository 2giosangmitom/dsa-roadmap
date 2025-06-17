#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    void solve(const vector<int>& nums, size_t i, vector<int>& subset,
               vector<vector<int>>& result) {
        result.push_back(subset);

        for (; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            solve(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        solve(nums, 0, subset, result);

        return result;
    }
};
