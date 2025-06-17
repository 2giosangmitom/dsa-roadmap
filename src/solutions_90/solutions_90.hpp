#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

class Solution {
   private:
    void solve(const vector<int>& nums, size_t i, vector<vector<int>>& result,
               vector<int>& subset) {
        result.push_back(subset);

        for (size_t j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }

            subset.push_back(nums[j]);
            solve(nums, j + 1, result, subset);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> candidate;

        solve(nums, 0, result, candidate);

        return result;
    }
};
