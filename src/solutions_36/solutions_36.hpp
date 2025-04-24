#pragma once

#include <array>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    array<unordered_set<char>, 9> col_set;
    array<unordered_set<char>, 9> row_set;
    array<array<unordered_set<char>, 3>, 3> cell_set;

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char c = board[i][j];

        if (c == '.') continue;

        if (row_set[i].contains(c) || cell_set[i / 3][j / 3].contains(c) ||
            col_set[j].contains(c)) {
          return false;
        }

        col_set[j].insert(c);
        row_set[i].insert(c);
        cell_set[i / 3][j / 3].insert(c);
      }
    }

    return true;
  }
};
