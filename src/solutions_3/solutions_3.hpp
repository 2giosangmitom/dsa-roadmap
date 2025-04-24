#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // The last position of the character
    unordered_map<char, size_t> last_seen;

    int result = 0;
    size_t left = 0;
    size_t right = 0;

    while (right < s.size()) {
      if (last_seen.contains(s[right]) && last_seen[s[right]] >= left) {
        left = last_seen[s[right]] + 1;
      }
      last_seen[s[right]] = right;
      result = max(result, int(right - left + 1));
      right++;
    }

    return result;
  }

  int lengthOfLongestSubstring2(string s) {
    int left = 0;
    int result = 0;
    unordered_set<char> char_set;

    for (size_t right = 0; right < s.length(); right++) {
      while (char_set.contains(s[right])) {
        char_set.erase(s[left]);
        left++;
      }

      char_set.insert(s[right]);
      result = max(result, int(right - left + 1));
    }

    return result;
  }
};
