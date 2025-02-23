#include "reverse_string.hpp"
#include <utility>

void Solution::reverseString(vector<char> &s) {
  for (size_t i = 0; i < s.size() / 2; i++) {
    swap(s[i], s[s.size() - i - 1]);
  }
}