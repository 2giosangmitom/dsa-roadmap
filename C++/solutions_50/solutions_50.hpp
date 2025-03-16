#pragma once

#include <cstdlib>

class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0)
      return 0;

    if (n == 0)
      return 1;

    double p = myPow(x, abs(n) / 2);
    p *= p;
    if (n % 2 == 1) {
      p *= x;
    }

    return n < 0 ? 1 / p : p;
  }
};
