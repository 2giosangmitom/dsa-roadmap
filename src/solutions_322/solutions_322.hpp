#pragma once

#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int top_down(vector<int>& coins, int amount,
                 unordered_map<int, int>& memo) {
        if (amount == 0) return 0;

        if (memo.contains(amount)) {
            return memo[amount];
        }

        long result = numeric_limits<int>::max();

        for (int coin : coins) {
            if (coin <= amount) {
                int num_coins = top_down(coins, amount - coin, memo);
                if (num_coins == -1) continue;
                result = min(result, 1L + num_coins);
            }
        }
        memo[amount] = result;

        return result == numeric_limits<int>::max() ? -1 : result;
    }

   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;

        for (int t = 1; t <= amount; t++) {
            for (const int& coin : coins) {
                if (coin <= t) {
                    dp[t] = min(dp[t], 1 + dp[t - coin]);
                }
            }
        }

        return dp[amount] != numeric_limits<int>::max() ? dp[amount] : -1;
    }

    int coinChange2(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return top_down(coins, amount, memo);
    }
};
