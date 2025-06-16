#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    unordered_map<int, int> memo;

   public:
    // Top-down approach
    int climbStairs(int n) {
        if (n <= 2) return n;

        if (memo.contains(n)) {
            return memo[n];
        }
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return memo[n];
    }

    // Bottom-up approach
    int climbStairs2(int n) {
        if (n <= 2) return n;

        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    // Bottom-up optimization
    int climbStairs3(int n) {
        if (n <= 2) return n;

        int one_step_before = 2, two_steps_before = 1;

        for (int i = 3; i <= n; i++) {
            int current = one_step_before + two_steps_before;
            two_steps_before = one_step_before;
            one_step_before = current;
        }

        return one_step_before;
    }
};
