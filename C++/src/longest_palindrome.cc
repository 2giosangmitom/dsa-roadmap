#include "longest_palindrome.hpp"
#include <unordered_map>

int Solution::longestPalindrome(string s) {
  unordered_map<char, int> frequencies;
  int res = 0;

  for (char &c : s) {
    frequencies[c]++;
  }

  bool has_odd = false;
  for (auto &entry : frequencies) {
    if (entry.second % 2 == 0) {
      res += entry.second;
    } else {
      res += entry.second - 1;
      has_odd = true;
    }
  }

  return has_odd ? res + 1 : res;
}
