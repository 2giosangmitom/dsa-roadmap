#include "set_matrix_zeroes.hpp"
#include <set>

void Solution::setZeroes(vector<vector<int>> &matrix) {
  set<int> cols;
  set<int> rows;

  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 0) {
        cols.insert(j);
        rows.insert(i);
      }
    }
  }

  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[0].size(); j++) {
      if (rows.contains(i) || cols.contains(j)) {
        matrix[i][j] = 0;
      }
    }
  }
}
