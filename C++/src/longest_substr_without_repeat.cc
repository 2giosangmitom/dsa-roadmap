#include "longest_substr_without_repeat.hpp"
#include <unordered_set>

int Solution::lengthOfLongestSubstring(string s) {
  unordered_set<char> set;
  int result = 0;
  int left = 0, right = 0;

  while (size_t(right) < s.size()) {
    while (set.contains(s[right])) {
      set.erase(s[left]);
      left++;
    }

    result = max(result, right - left + 1);
    set.insert(s[right]);
    right++;
  }

  return result;
}
