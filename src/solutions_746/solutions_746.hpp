#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int solve(vector<int>& cost, size_t stair, unordered_map<int, int>& memo) {
        if (stair <= 1) {
            return cost[stair];
        }

        if (memo.contains(stair)) {
            return memo[stair];
        }

        memo[stair] =
            (stair < cost.size() ? cost[stair] : 0) +
            min(solve(cost, stair - 1, memo), solve(cost, stair - 2, memo));

        return memo[stair];
    }

   public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> memo;
        return solve(cost, cost.size(), memo);
    }

    int minCostClimbingStairs2(vector<int>& cost) {
        size_t n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = cost[1];

        for (size_t i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};
