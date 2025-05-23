#pragma once

#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int egde_len = matrix.size();

    int top = 0;
    int bottom = egde_len - 1;

    while (top < bottom) {
      for (int i = 0; i < egde_len; i++) {
        std::swap(matrix[top][i], matrix[bottom][i]);
      }
      top++;
      bottom--;
    }

    for (int i = 0; i < egde_len; i++) {
      for (int j = i + 1; j < egde_len; j++) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
