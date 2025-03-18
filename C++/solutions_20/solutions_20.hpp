#pragma once

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    int length = s.length();
    if (length % 2 != 0) {
      return false;
    }

    vector<char> stack = {};
    for (int i = 0; i < length; i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stack.push_back(s[i]);
      } else {
        if (stack.empty()) {
          return false;
        }

        if ((s[i] == ')' && stack.back() == '(') ||
            (s[i] == '}' && stack.back() == '{') ||
            (s[i] == ']' && stack.back() == '[')) {
          stack.pop_back();
        } else {
          return false;
        }
      }
    }

    return stack.empty();
  }
};
