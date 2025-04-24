#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int k = 0;

    int length = nums.size();
    int count = 0;

    for (int i = 0; i < length; i++) {
      if (i == 0 || (i > 0 && nums[i - 1] == nums[i])) {
        count++;
      } else {
        count = 1;
      }

      if (count <= 2) {
        nums[k++] = nums[i];
      }
    }

    return k;
  }
};
