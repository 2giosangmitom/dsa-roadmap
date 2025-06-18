#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int solve(vector<int>& days, vector<int>& costs, size_t i,
              int valid_until_day, unordered_map<string, int>& memo) {
        if (i == days.size()) {
            return 0;
        }

        // Return cached value if found
        string key = to_string(i) + "-" + to_string(valid_until_day);
        if (memo.contains(key)) {
            return memo[key];
        }

        // If the current day is already covered, move to next day
        if (days[i] < valid_until_day) {
            memo[key] = solve(days, costs, i + 1, valid_until_day, memo);
            return memo[key];
        }

        // Buy a new pass at days[i]
        int cost1 = costs[0] + solve(days, costs, i + 1, days[i] + 1, memo);
        int cost7 = costs[1] + solve(days, costs, i + 1, days[i] + 7, memo);
        int cost30 = costs[2] + solve(days, costs, i + 1, days[i] + 30, memo);
        memo[key] = min({cost1, cost7, cost30});

        return memo[key];
    }

   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<string, int> memo;
        return solve(days, costs, 0, 0, memo);
    }

    int mincostTickets2(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);

        int i = 0;
        for (int day = 1; day <= days.back(); day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] =
                    min({dp[day - 1] + costs[0], dp[max(0, day - 7)] + costs[1],
                         dp[max(0, day - 30)] + costs[2]});
            }
        }

        return dp[days.back()];
    }
};
