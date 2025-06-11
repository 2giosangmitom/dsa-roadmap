#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   private:
    void solve(const vector<int>& candidates, int target, size_t i,
               vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;

        size_t n = candidates.size();
        while (i < n) {
            // Optimization: since the candidates is sorted, if current
            // candidate is larger than target, we can break early
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, current, result);
            current.pop_back();
            i++;
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, current, result);

        return result;
    }
};
