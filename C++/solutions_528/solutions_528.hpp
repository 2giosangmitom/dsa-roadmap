#pragma once

#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> prefix_sums;
  vector<int> weights;

public:
  Solution(vector<int> &w) : weights{w} {
    prefix_sums.resize(weights.size());

    prefix_sums[0] = weights[0];
    for (size_t i = 1; i < weights.size(); i++) {
      prefix_sums[i] = prefix_sums[i - 1] + weights[i];
    }
  }

  int pickIndex() {
    int target = 1 + rand() % prefix_sums.back();

    int left = 0;
    int right = prefix_sums.size() - 1;

    while (left < right) {
      int mid = (left + right) / 2;

      if (prefix_sums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
