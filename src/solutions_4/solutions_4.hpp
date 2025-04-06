#pragma once

#include <cmath>
#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Optimization: ensure the nums1 is always smaller
    if (nums2.size() < nums1.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(), n = nums2.size();
    // Divide the merged array into two partitions
    int half_total_len = (m + n) / 2;
    int left = 0, right = m - 1;

    while (true) {
      int L1_index = floor((left + right) / 2.0);
      int L2_index = half_total_len - (L1_index + 1) - 1;

      int L1 = (L1_index < 0) ? INT32_MIN : nums1[L1_index];
      int R1 = (L1_index >= m - 1) ? INT32_MAX : nums1[L1_index + 1];
      int L2 = (L2_index < 0) ? INT32_MIN : nums2[L2_index];
      int R2 = (L2_index >= n - 1) ? INT32_MAX : nums2[L2_index + 1];

      if (L1 <= R2 && L2 <= R1) {
        // Correct slice
        if ((m + n) % 2 == 0) {
          return (max(L1, L2) + min(R1, R2)) / 2.0;
        } else {
          return min(R1, R2);
        }
      } else if (L2 > R1) {
        left = L1_index + 1;
      } else {
        right = L1_index - 1;
      }
    }
  }
};
