#pragma once

#include <cmath>

class Solution {
 public:
  bool isThree(int n) {
    int count = 0;
    for (int i = 1; i <= std::sqrt(n); i++) {
      if (n % i == 0) {
        count++;
        if (i != n / i) {
          count++;
        }
      }
      // If number of divisors exceed 3, we can return early.
      if (count > 3) {
        return false;
      }
    }
    return count == 3;
  }
};