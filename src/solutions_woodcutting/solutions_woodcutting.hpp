#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 private:
  bool cut_enough_wood(int H, vector<int> &A, int B) {
    long res = 0;

    for (int h : A) {
      if (h > H) {
        res += h - H;
      }
    }

    return res >= B;
  }

 public:
  int solve(vector<int> &A, int B) {
    int left = 0;
    int right = *max_element(A.begin(), A.end());

    while (left < right) {
      int mid = (left + right) / 2 + 1;

      if (cut_enough_wood(mid, A, B)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }

    return right;
  }
};
