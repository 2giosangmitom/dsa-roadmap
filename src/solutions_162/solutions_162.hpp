#pragma once

#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      size_t mid = (left + right) / 2;
      int next_value = mid < nums.size() ? nums[mid + 1] : INT32_MAX;

      if (nums[mid] < next_value) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
