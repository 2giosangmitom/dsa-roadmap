#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();

    if (k != 0) {
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k);
      reverse(nums.begin() + k, nums.end());
    }
  }
};
