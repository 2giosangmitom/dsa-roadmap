#include "longest_substr_without_repeat.hpp"
#include <unordered_map>

int Solution::lengthOfLongestSubstring(string s) {
  unordered_map<char, int> prev_indexes;
  int max_len = 0;
  int left = 0, right = 0;

  while (size_t(right) < s.size()) {
    if (prev_indexes.contains(s[right]) && prev_indexes[s[right]] >= left) {
      left = prev_indexes[s[right]] + 1;
    }

    max_len = max(max_len, right - left + 1);
    prev_indexes[s[right]] = right;
    right++;
  }

  return max_len;
}
