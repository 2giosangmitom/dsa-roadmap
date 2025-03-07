#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int actual_sum = 0;
    long actual_sum_square = 0;
    int n = grid.size() * grid.size();
    int expected_sum = (n * (1 + n)) / 2;
    long expected_sum_square = (n * (1L + n) * (2L * n + 1L)) / 6L;

    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid.size(); j++) {
        actual_sum += grid[i][j];
        actual_sum_square += grid[i][j] * grid[i][j];
      }
    }

    // (a + b)(a - b) = (a^2 - b^2)
    long q = actual_sum_square - expected_sum_square;  // a^2 - b^2
    long p = actual_sum - expected_sum;                // a - b
    long r = q / p;                                    // a + b

    int a = (p + r) / 2;
    int b = r - a;

    return {a, b};
  }

  vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
    int actual_sum = 0;
    int grid_size = grid.size() * grid.size();
    int expected_sum = (grid_size * (1 + grid_size)) / 2;
    int a;
    unordered_map<int, int> freq;

    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid.size(); j++) {
        actual_sum += grid[i][j];
        freq[grid[i][j]]++;
        if (freq[grid[i][j]] == 2) {
          a = grid[i][j];
        }
      }
    }

    int b = (expected_sum - actual_sum + a);

    return {a, b};
  }
};
