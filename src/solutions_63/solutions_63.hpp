#pragma once

#include <vector>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto r = obstacleGrid.size(), c = obstacleGrid[0].size();
        if (obstacleGrid[r - 1][c - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(r, vector<int>(c));

        for (size_t i = 0; i < r; i++) {
            if (obstacleGrid[i][0] == 1) {
                while (i < r) {
                    dp[i][0] = 0;
                    i++;
                }
            } else {
                dp[i][0] = 1;
            }
        }
        for (size_t i = 0; i < c; i++) {
            if (obstacleGrid[0][i] == 1) {
                while (i < c) {
                    dp[0][i] = 0;
                    i++;
                }
            } else {
                dp[0][i] = 1;
            }
        }

        for (size_t i = 1; i < r; i++) {
            for (size_t j = 1; j < c; j++) {
                dp[i][j] =
                    obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[r - 1][c - 1];
    }
};
