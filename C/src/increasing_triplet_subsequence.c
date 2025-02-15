#include "increasing_triplet_subsequence.h"
#include <stdint.h>

bool increasingTriplet(int *nums, int numsSize) {
  int first = INT32_MAX, second = INT32_MAX;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] <= first) {
      first = nums[i];
    } else if (nums[i] <= second) {
      second = nums[i];
    } else {
      return true;
    }
  }

  return false;
}
