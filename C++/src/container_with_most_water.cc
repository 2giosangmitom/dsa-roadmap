#include "container_with_most_water.hpp"

int Solution::maxArea(vector<int> &height) {
  int res = 0;

  int left = 0;
  int right = height.size() - 1;

  while (left < right) {
    int area = (right - left) * min(height[left], height[right]);
    res = max(res, area);

    if (height[left] == height[right]) {
      left++;
      right--;
    } else if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return res;
}
