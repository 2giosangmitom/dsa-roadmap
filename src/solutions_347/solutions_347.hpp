#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> result;
    unordered_map<int, int> freq;

    for (const int &num : nums) {
      freq[num]++;
    }

    for (auto &pair : freq) {
      result.push_back(pair.first);
      push_heap(result.begin(), result.end(),
                [&freq](int a, int b) { return freq[a] > freq[b]; });

      if (result.size() > static_cast<size_t>(k)) {
        pop_heap(result.begin(), result.end(),
                 [&freq](int a, int b) { return freq[a] > freq[b]; });
        result.pop_back();
      }
    }

    return result;
  }
};
