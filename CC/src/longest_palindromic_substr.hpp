#ifndef LONGEST_PALINDROMIC_SUBSTR
#define LONGEST_PALINDROMIC_SUBSTR

#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty())
      return "";
    if (s.size() == 1)
      return s;

    int start = 0, max_len = 1;

    for (size_t i = 0; i < s.size(); ++i) {
      int len1 = expandAroundCenter(s, i, i);     // odd-length palindromes
      int len2 = expandAroundCenter(s, i, i + 1); // even-length palindromes

      int len = max(len1, len2);
      if (len > max_len) {
        start = i - (len - 1) / 2;
        max_len = len;
      }
    }

    return s.substr(start, max_len);
  }

private:
  int expandAroundCenter(const string &s, int left, int right) {
    int size = s.size();
    while (left >= 0 && right < size && s[left] == s[right]) {
      --left;
      ++right;
    }
    return right - left - 1;
  }
};

#endif // !LONGEST_PALINDROMIC_SUBSTR
