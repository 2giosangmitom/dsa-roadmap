#pragma once

#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> twoSum(size_t left, vector<int> &nums, int target);

public:
  vector<vector<int>> threeSum(vector<int> &nums);
};
