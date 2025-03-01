#include "remove_element.hpp"

int Solution::removeElement(vector<int> &nums, int val) {
  int left = 0;

  for (size_t right = 0; right < nums.size(); right++) {
    if (nums[right] != val) {
      nums[left++] = nums[right];
    }
  }

  return left;
}
