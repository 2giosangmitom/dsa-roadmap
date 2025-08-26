#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        grid[i][j] = 'x';  // Mark this cell as visited

        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            dfs(grid, i - 1, j, n, m);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            dfs(grid, i, j - 1, n, m);
        }
        if (i + 1 < n && grid[i + 1][j] == '1') {
            dfs(grid, i + 1, j, n, m);
        }
        if (j + 1 < m && grid[i][j + 1] == '1') {
            dfs(grid, i, j + 1, n, m);
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    ++count;
                }
            }
        }

        return count;
    }
};
