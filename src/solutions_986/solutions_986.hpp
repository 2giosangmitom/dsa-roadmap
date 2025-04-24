#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> intersections;
    size_t i = 0;
    size_t j = 0;

    while (i < firstList.size() && j < secondList.size()) {
      vector<int> A = firstList[i];
      vector<int> B = secondList[j];
      if (A[0] > B[0]) {
        swap(A, B);
      }

      if (A[1] >= B[0]) intersections.push_back({B[0], min(A[1], B[1])});

      if (firstList[i][1] < secondList[j][1]) {
        i++;
      } else if (firstList[i][1] > secondList[j][1]) {
        j++;
      } else {
        i++;
        j++;
      }
    }

    return intersections;
  }
};
