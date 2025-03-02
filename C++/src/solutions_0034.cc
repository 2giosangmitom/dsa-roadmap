#include "solutions_0034.hpp"
#include <vector>

int Solution::lower_bound(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = (left + right) / 2;

    if (nums[mid] == target) {
      right = mid;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return nums[left] == target ? left : -1;
}

int Solution::upper_bound(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = (left + right) / 2 + 1;

    if (nums[mid] == target) {
      left = mid;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return nums[right] == target ? right : -1;
}

vector<int> Solution::searchRange(vector<int> &nums, int target) {
  if (nums.empty()) {
    return {-1, -1};
  }

  int left = lower_bound(nums, target);
  int right = upper_bound(nums, target);

  return {left, right};
}