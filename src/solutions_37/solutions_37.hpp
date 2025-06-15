#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    vector<pair<int, int>> empty_cells;

    bool solve(vector<vector<char>> &board, vector<vector<bool>> &rows,
               vector<vector<bool>> &cols, vector<vector<vector<bool>>> &boxes,
               size_t idx) {
        if (idx == empty_cells.size()) return true;

        auto [i, j] = empty_cells[idx];

        for (char num = '1'; num <= '9'; num++) {
            int d = num - '1';  // index 0-8
            if (!rows[i][d] && !cols[j][d] && !boxes[i / 3][j / 3][d]) {
                board[i][j] = num;
                rows[i][d] = cols[j][d] = boxes[i / 3][j / 3][d] = true;

                if (solve(board, rows, cols, boxes, idx + 1)) return true;

                board[i][j] = '.';
                rows[i][d] = cols[j][d] = boxes[i / 3][j / 3][d] = false;
            }
        }

        return false;
    }

   public:
    void solveSudoku(vector<vector<char>> &board) {
        // Hash set indicate whether a row/col/cells includes a number
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> boxes(
            3, vector<vector<bool>>(3, vector<bool>(9, false)));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    empty_cells.emplace_back(i, j);
                } else {
                    int d = c - '1';
                    rows[i][d] = cols[j][d] = boxes[i / 3][j / 3][d] = true;
                }
            }
        }

        solve(board, rows, cols, boxes, 0);
    }
};
