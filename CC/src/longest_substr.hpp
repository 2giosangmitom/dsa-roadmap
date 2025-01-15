#ifndef LONGEST_SUBSTR_HPP
#define LONGEST_SUBSTR_HPP

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    unordered_set<char> ch;
    int i = 0, j = 0;
    int len = s.size();

    while (j < len) {
      if (!ch.contains(s[j])) {
        ch.insert(s[j]);
        max_len = max(max_len, j - i + 1);
        j++;
      } else {
        ch.erase(s[i]);
        i++;
      }
    }

    return max_len;
  }
};

#endif // !LONGEST_SUBSTR_HPP
