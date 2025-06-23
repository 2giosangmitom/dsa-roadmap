#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (size_t i = 0; i <= m; i++) {
            dp[i][n] = 0;
        }
        for (size_t i = 0; i <= n; i++) {
            dp[m][i] = 0;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
