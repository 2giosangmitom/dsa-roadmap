#pragma once

#include <vector>
using namespace std;

class Solution {
private:
  int lower_bound(vector<int> &nums, int target);
  int upper_bound(vector<int> &nums, int target);

public:
  vector<int> searchRange(vector<int> &nums, int target);
};