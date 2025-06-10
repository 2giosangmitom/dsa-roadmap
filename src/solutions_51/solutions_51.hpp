#pragma once

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 private:
  void solve(int r, std::unordered_set<int>& diagonals_set,
             std::unordered_set<int>& anti_diagonals_set,
             std::unordered_set<int>& cols_set, int n,
             std::vector<std::vector<std::string>>& result,
             std::vector<std::string>& current) {
    if (r == n) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < n; i++) {
      int curr_diagonals = r - i;
      int curr_anti_diagonals = r + i;
      if (cols_set.contains(i) || diagonals_set.contains(curr_diagonals) ||
          anti_diagonals_set.contains(curr_anti_diagonals)) {
        continue;
      }

      cols_set.insert(i);
      diagonals_set.insert(curr_diagonals);
      anti_diagonals_set.insert(curr_anti_diagonals);
      std::string row(n, '.');
      row[i] = 'Q';
      current.push_back(row);
      solve(r + 1, diagonals_set, anti_diagonals_set, cols_set, n, result,
            current);
      current.pop_back();
      cols_set.erase(i);
      diagonals_set.erase(curr_diagonals);
      anti_diagonals_set.erase(curr_anti_diagonals);
    }
  }

 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;
    std::unordered_set<int> diagonals_set;
    std::unordered_set<int> anti_diagonals_set;
    std::unordered_set<int> cols_set;

    solve(0, diagonals_set, anti_diagonals_set, cols_set, n, result, current);

    return result;
  }
};
