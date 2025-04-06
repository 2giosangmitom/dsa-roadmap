#pragma once

#include <cstdint>
#include <string>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int i = 0, n = s.length();
    // Skip leading white spaces
    while (i < n && s[i] == ' ') {
      i++;
    }

    if (i == n)
      return 0; // If string contains only spaces

    int sign = 1; // Default is positive
    if (s[i] == '+' || s[i] == '-') {
      sign = (s[i] == '-') ? -1 : 1;
      i++;
    }

    long long result = 0;
    while (i < n && isdigit(s[i])) {
      result = result * 10 + (s[i] - '0');
      if (result * sign > INT32_MAX)
        return INT32_MAX;
      if (result * sign < INT32_MIN)
        return INT32_MIN;
      i++;
    }

    return (int)(result * sign);
  }
};