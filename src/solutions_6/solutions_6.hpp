#pragma once

#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;

    std::vector<std::string> rows(numRows);

    int dir = -1;
    int i = 0;
    for (char c : s) {
      if (i == 0 || i == numRows - 1) dir *= -1;

      rows[i].push_back(c);

      i += dir;
    }

    return std::accumulate(rows.begin(), rows.end(), std::string{});
  }
};