#pragma once

#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        auto m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        int max_size = 0;
        for (size_t i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                max_size = 1;
            } else {
                dp[i][0] = 0;
            }
        }
        for (size_t i = 0; i < n; i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                max_size = 1;
            } else {
                dp[0][i] = 0;
            }
        }

        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    max_size = max(max_size, dp[i][j]);
                }
            }
        }

        return pow(max_size, 2);
    }
};
