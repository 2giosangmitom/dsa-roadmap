#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    void solve(int n, int k, int i, vector<vector<int>>& result,
               vector<int>& candidate) {
        if (candidate.size() == static_cast<size_t>(k)) {
            result.push_back(candidate);
            return;
        }

        while (i <= n) {
            candidate.push_back(i);
            solve(n, k, i + 1, result, candidate);
            candidate.pop_back();
            i++;
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> candidate;

        solve(n, k, 1, result, candidate);

        return result;
    }
};
