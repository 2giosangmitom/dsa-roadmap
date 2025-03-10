#pragma once

#include <string>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (!isalpha(s[left]) && !isdigit(s[left])) {
        left++;
        continue;
      }
      if (!isalpha(s[right]) && !isdigit(s[right])) {
        right--;
        continue;
      }
      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};
