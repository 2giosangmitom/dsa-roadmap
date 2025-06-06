#pragma once

#include <array>
#include <string>
#include <vector>

class Solution {
 private:
  bool is_within_bounds(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
  }

  bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i,
           int j, int index, int n, int m) {
    if (index == static_cast<int>(word.size())) {
      return true;  // Found the word
    }

    std::array<std::pair<int, int>, 4> directions = {
        std::make_pair(0, 1),   // Right
        std::make_pair(1, 0),   // Down
        std::make_pair(0, -1),  // Left
        std::make_pair(-1, 0)   // Up
    };

    char temp = board[i][j];
    board[i][j] = '#';  // Mark as visited

    for (auto& dir : directions) {
      int new_i = i + dir.first;
      int new_j = j + dir.second;

      if (!is_within_bounds(new_i, new_j, n, m)) {
        continue;  // Skip out of bounds
      }

      if (board[new_i][new_j] == word[index]) {
        if (dfs(board, word, new_i, new_j, index + 1, n, m)) {
          return true;  // Found the word in this direction
        }
      }
    }

    board[i][j] = temp;  // Restore the original character

    return false;
  }

 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    int n = board.size(), m = board[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          if (dfs(board, word, i, j, 1, n, m)) {
            return true;  // Found the word starting from (i, j)
          }
        }
      }
    }

    return false;
  }
};