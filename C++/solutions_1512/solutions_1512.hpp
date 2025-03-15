#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> freq;
    int result = 0;

    for (int n : nums) {
      if (freq.contains(n)) {
        result += freq[n]++;
      } else {
        freq[n] = 1;
      }
    }

    return result;
  }
};
