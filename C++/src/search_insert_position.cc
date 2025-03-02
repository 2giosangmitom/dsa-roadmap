#include "search_insert_position.hpp"

int Solution::searchInsert(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size();

  while (left < right) {
    int mid = (left + right) / 2;

    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}
