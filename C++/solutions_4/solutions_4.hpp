#include <cstdint>
#include <vector>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m) {
      swap(nums1, nums2);
      swap(n, m);
    }

    int total_len = n + m;
    int half = (total_len + 1) / 2;
    int left = 0, right = n;

    while (true) {
      int l1_i = (left + right) / 2;
      int l2_i = half - l1_i;

      int L1 = (l1_i > 0) ? nums1[l1_i - 1] : INT32_MIN;
      int L2 = (l2_i > 0) ? nums2[l2_i - 1] : INT32_MIN;
      int R1 = (l1_i < n) ? nums1[l1_i] : INT32_MAX;
      int R2 = (l2_i < m) ? nums2[l2_i] : INT32_MAX;

      if (L1 <= R2 && L2 <= R1) {
        if (total_len % 2 == 0) {
          return (max(L1, L2) + min(R1, R2)) / 2.0;
        }
        return max(L1, L2);
      } else if (L1 > R2) {
        right = l1_i - 1;
      } else {
        left = l1_i + 1;
      }
    }
  }
};
