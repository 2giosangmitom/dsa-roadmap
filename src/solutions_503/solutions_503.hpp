#pragma once

#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> stack;
    vector<int> res(nums.size());

    for (int i = (2 * nums.size()) - 1; i >= 0; i--) {
      while (!stack.empty() && stack.top() <= nums[i % nums.size()]) {
        stack.pop();
      }

      res[i % nums.size()] = stack.empty() ? -1 : stack.top();
      stack.push(nums[i % nums.size()]);
    }

    return res;
  }
};
