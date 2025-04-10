#pragma once

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> result(nums.size());

    // Performing left prefix product
    for (size_t i = 0; i < nums.size(); i++) {
      result[i] = (i > 0 ? result[i - 1] * nums[i - 1] : 1);
    }

    // Performing right prefix product
    int right_product = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      result[i] *= right_product;
      right_product *= nums[i];
    }

    return result;
  }

  vector<int> productExceptSelf2(vector<int> &nums) {
    vector<int> result(nums.size());

    int total_product = 1;
    int count_zeroes = 0;
    for (int &num : nums) {
      if (num != 0) {
        total_product *= num;
      } else {
        count_zeroes++;
      }
    }

    if (count_zeroes >= 2) {
      result.assign(result.size(), 0);
    } else {
      for (size_t i = 0; i < nums.size(); i++) {
        if (count_zeroes == 0) {
          result[i] = total_product / nums[i];
        } else {
          if (nums[i] == 0) {
            result[i] = total_product;
          } else {
            result[i] = 0;
          }
        }
      }
    }

    return result;
  }
};
