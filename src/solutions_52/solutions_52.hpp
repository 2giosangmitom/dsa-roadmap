#pragma once

#include <unordered_set>

class Solution {
   private:
    void helper(int n, int r, int& result, std::unordered_set<int>& cols_set,
                std::unordered_set<int>& diagonals_set,
                std::unordered_set<int>& anti_diagonals_set) {
        if (r == n) {
            result++;
            return;
        }

        for (int i = 0; i < n; i++) {
            int current_diagonal = r - i;
            int current_anti_diagonal = r + i;

            if (cols_set.contains(i) ||
                diagonals_set.contains(current_diagonal) ||
                anti_diagonals_set.contains(current_anti_diagonal)) {
                continue;
            }

            cols_set.insert(i);
            diagonals_set.insert(current_diagonal);
            anti_diagonals_set.insert(current_anti_diagonal);
            helper(n, r + 1, result, cols_set, diagonals_set,
                   anti_diagonals_set);
            cols_set.erase(i);
            diagonals_set.erase(current_diagonal);
            anti_diagonals_set.erase(current_anti_diagonal);
        }
    }

   public:
    int totalNQueens(int n) {
        int result = 0;
        std::unordered_set<int> cols_set;
        std::unordered_set<int> diagonals_set;
        std::unordered_set<int> anti_diagonals_set;
        helper(n, 0, result, cols_set, diagonals_set, anti_diagonals_set);
        return result;
    }
};
