#include "valid_sudoku.hpp"

#include <array>
#include <set>

bool Solution::isValidSudoku(vector<vector<char>> &board) {
  array<set<char>, 9> row_sets;
  array<set<char>, 9> col_sets;
  array<array<set<char>, 3>, 3> subgrid_sets;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.')
        continue;

      // Check row_sets
      if (row_sets[i].contains(board[i][j])) {
        return false;
      }

      // Check col_sets
      if (col_sets[j].contains(board[i][j])) {
        return false;
      }

      // Check subgrid_sets
      if (subgrid_sets[i / 3][j / 3].contains(board[i][j])) {
        return false;
      }

      subgrid_sets[i / 3][j / 3].insert(board[i][j]);
      row_sets[i].insert(board[i][j]);
      col_sets[j].insert(board[i][j]);
    }
  }

  return true;
}
