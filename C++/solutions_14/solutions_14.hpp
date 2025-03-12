#pragma once

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];

    for (size_t i = 1; i < strs.size(); i++) {
      while (strs[i].find(prefix) != 0) {
        prefix.erase(prefix.end() - 1);
        if (prefix.empty()) return "";
      }
    }

    return prefix;
  }
};
