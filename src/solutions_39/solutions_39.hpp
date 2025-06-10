#pragma once

#include <vector>
using namespace std;

class Solution {
 private:
  void solve(const vector<int>& candidates, int target, size_t start_index,
             vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
      result.push_back(current);
      return;
    }
    if (target < 0) return;

    size_t n = candidates.size();
    while (start_index < n) {
      current.push_back(candidates[start_index]);
      solve(candidates, target - candidates[start_index], start_index, current,
            result);
      current.pop_back();
      start_index++;
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;

    solve(candidates, target, 0, current, result);

    return result;
  }
};
