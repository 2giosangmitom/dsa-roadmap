#pragma once

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, size_t> prev_indexes;

    int result = 0;
    size_t left = 0;
    size_t right = 0;

    while (right < s.size()) {
      if (prev_indexes.contains(s[right]) && prev_indexes[s[right]] >= left) {
        left = prev_indexes[s[right]] + 1;
      }
      prev_indexes[s[right]] = right;
      result = max(result, int(right - left + 1));
      right++;
    }

    return result;
  }
};
