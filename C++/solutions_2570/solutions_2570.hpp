#pragma once

#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    map<int, int> e;

    for (auto &entry : nums1) {
      e[entry[0]] += entry[1];
    }
    for (auto &entry : nums2) {
      e[entry[0]] += entry[1];
    }

    vector<vector<int>> result(e.size());

    int i = 0;
    for (auto &entry : e) {
      result[i++] = {entry.first, entry.second};
    }

    return result;
  }

  vector<vector<int>> mergeArrays2(vector<vector<int>> &nums1,
                                   vector<vector<int>> &nums2) {
    size_t i = 0;
    size_t j = 0;

    vector<vector<int>> result;

    while (i < nums1.size() && j < nums2.size()) {
      auto p1 = nums1[i];
      auto p2 = nums2[j];

      if (nums1[i][0] == nums2[j][0]) {
        result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
        i++;
        j++;
      } else if (nums1[i][0] < nums2[j][0]) {
        result.push_back({nums1[i][0], nums1[i][1]});
        i++;
      } else {
        result.push_back({nums2[j][0], nums2[j][1]});
        j++;
      }
    }

    while (i < nums1.size()) {
      result.push_back({nums1[i][0], nums1[i][1]});
      i++;
    }

    while (j < nums2.size()) {
      result.push_back({nums2[j][0], nums2[j][1]});
      j++;
    }

    return result;
  }
};
