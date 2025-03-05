#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix.size() * matrix[0].size() - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      int c = mid % matrix[0].size();
      int r = mid / matrix[0].size();

      if (matrix[r][c] == target) {
        return true;
      } else if (matrix[r][c] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }
};
