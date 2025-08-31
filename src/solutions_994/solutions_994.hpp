#pragma once

#include <queue>
#include <vector>
using namespace std;

class Solution {
   private:
    inline bool is_in_bound(int n, int m, int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int>> q;
        int seconds = 0;
        int count_one = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++count_one;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        tuple<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (count_one > 0 && !q.empty()) {
            int level_len = q.size();
            ++seconds;
            for (int i = 0; i < level_len; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [nr, nc] : dirs) {
                    int next_row = r + nr;
                    int next_col = c + nc;

                    if (!is_in_bound(n, m, next_row, next_col)) {
                        continue;
                    }

                    if (grid[next_row][next_col] == 1) {
                        grid[next_row][next_col] = 2;
                        --count_one;
                        q.push({next_row, next_col});
                    }
                }
            }
        }

        return count_one > 0 ? -1 : seconds;
    }
};
