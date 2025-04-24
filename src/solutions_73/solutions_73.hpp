#pragma once

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
    unordered_set<int> cols;
    unordered_set<int> rows;

    int cols_num = matrix.size();
    int rows_num = matrix[0].size();

    for (int i = 0; i < cols_num; i++) {
      for (int j = 0; j < rows_num; j++) {
        if (matrix[i][j] == 0) {
          cols.insert(j);
          rows.insert(i);
        }
      }
    }

    for (int i = 0; i < cols_num; i++) {
      for (int j = 0; j < rows_num; j++) {
        if (rows.contains(i) || cols.contains(j)) {
          matrix[i][j] = 0;
        }
      }
    }
  }

  void setZeroes2(vector<vector<int>> &matrix) {
    bool first_row_has_zero = false;
    bool first_col_has_zero = false;

    int cols = matrix.size();
    int rows = matrix[0].size();

    for (int i = 0; i < rows; i++) {
      if (matrix[0][i] == 0) {
        first_col_has_zero = true;
        break;
      }
    }

    for (int i = 0; i < cols; i++) {
      if (matrix[i][0] == 0) {
        first_row_has_zero = true;
        break;
      }
    }

    for (int i = 1; i < cols; i++) {
      for (int j = 1; j < rows; j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = 1; i < cols; i++) {
      for (int j = 1; j < rows; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (first_row_has_zero) {
      for (int i = 0; i < cols; i++) {
        matrix[i][0] = 0;
      }
    }

    if (first_col_has_zero) {
      for (int i = 0; i < rows; i++) {
        matrix[0][i] = 0;
      }
    }
  }
};
