#pragma once

#include <vector>

class Solution {
 public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<std::vector<int>> result(rowIndex + 1);

    for (int i = 0; i < rowIndex + 1; i++) {
      result[i].resize(i + 1);
      result[i][0] = result[i][i] = 1;

      if (i >= 2) {
        for (int j = 1; j < i; j++) {
          result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
        }
      }
    }

    return result[rowIndex];
  }
};
