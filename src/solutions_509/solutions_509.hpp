#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    unordered_map<int, int> memo;

   public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fib2(int n) {
        if (n <= 1) return n;

        if (memo.contains(n)) {
            return memo[n];
        }
        memo[n] = fib2(n - 1) + fib2(n - 2);

        return memo[n];
    }
};
