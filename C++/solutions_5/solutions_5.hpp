#pragma once

#include <string>
using namespace std;

class Solution {
private:
  size_t expandCenter(const string &s, int left, int right) {
    while (left >= 0 && right < int(s.size())) {
      if (s[left] != s[right])
        break;
      left--;
      right++;
    }

    return right - left - 1;
  }

public:
  string longestPalindrome(string s) {
    string result = "";

    for (size_t i = 0; i < s.size(); i++) {
      size_t even = expandCenter(s, i, i + 1);
      size_t odd = expandCenter(s, i, i);
      size_t max_len = max(even, odd);

      if (max_len > result.size()) {
        size_t start = i + max_len / 2 + 1 - max_len;
        result = s.substr(start, max_len);
      }
    }

    return result;
  }
};