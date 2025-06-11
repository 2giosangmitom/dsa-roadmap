#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   private:
    void solve(size_t i, vector<vector<int>>& result, vector<int>& current,
               int target, const vector<int>& candidates, vector<bool>& used) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) {
            return;
        }

        const size_t n = candidates.size();
        while (i < n) {
            // Optimization: since the candidates is sorted, if current
            // candidate is larger than target, we can break early
            if (candidates[i] > target) {
                break;
            }
            if (i > 0 && candidates[i - 1] == candidates[i] && !used[i - 1]) {
                i++;
                continue;
            }

            current.push_back(candidates[i]);
            used[i] = true;
            solve(i + 1, result, current, target - candidates[i], candidates,
                  used);
            used[i] = false;
            current.pop_back();
            i++;
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());

        solve(0, result, current, target, candidates, used);

        return result;
    }
};
