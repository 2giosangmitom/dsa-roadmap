#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto a, auto b) { return a[0] < b[0]; });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); i++) {
      vector<int> &back = merged.back();

      if (back[1] >= intervals[i][0]) {
        back[1] = max(back[1], intervals[i][1]);
      } else {
        merged.push_back(intervals[i]);
      }
    }

    return merged;
  }
};
