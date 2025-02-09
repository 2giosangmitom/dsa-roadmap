#pragma once

#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> twoSum(int left, vector<int> &nums, int target);

public:
  vector<vector<int>> threeSum(vector<int> &nums);
};
