#include "set_matrix_zeroes.hpp"
#include <cstddef>
#include <set>

void Solution::setZeroes(vector<vector<int>> &matrix) {
  set<int> cols;
  set<int> rows;

  size_t cols_num = matrix.size();
  size_t rows_num = matrix[0].size();

  for (size_t i = 0; i < cols_num; i++) {
    for (size_t j = 0; j < rows_num; j++) {
      if (matrix[i][j] == 0) {
        cols.insert(int(i));
        rows.insert(int(j));
      }
    }
  }

  for (size_t i = 0; i < cols_num; i++) {
    for (size_t j = 0; j < rows_num; j++) {
      if (rows.contains(int(i)) || cols.contains(int(j))) {
        matrix[i][j] = 0;
      }
    }
  }
}

void Solution::setZeroes2(vector<vector<int>> &matrix) {
  bool first_row_has_zero = false;
  bool first_col_has_zero = false;

  size_t cols = matrix.size();
  size_t rows = matrix[0].size();

  for (size_t i = 0; i < rows; i++) {
    if (matrix[0][i] == 0) {
      first_col_has_zero = true;
      break;
    }
  }

  for (size_t i = 0; i < cols; i++) {
    if (matrix[i][0] == 0) {
      first_row_has_zero = true;
      break;
    }
  }

  for (size_t i = 1; i < cols; i++) {
    for (size_t j = 1; j < rows; j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }

  for (size_t i = 1; i < cols; i++) {
    for (size_t j = 1; j < rows; j++) {
      if (matrix[0][j] == 0 || matrix[i][0] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  if (first_row_has_zero) {
    for (size_t i = 0; i < cols; i++) {
      matrix[i][0] = 0;
    }
  }

  if (first_col_has_zero) {
    for (size_t i = 0; i < rows; i++) {
      matrix[0][i] = 0;
    }
  }
}
