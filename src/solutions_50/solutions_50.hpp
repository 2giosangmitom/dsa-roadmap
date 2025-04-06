#pragma once

#include <cstdlib>

class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0)
      return 0;
    if (n == 0)
      return 1;

    long N = n;
    if (N < 0) {
      x = 1 / x;
      N = -N;
    }

    double result = helper(x, N);
    return result;
  }

private:
  double helper(double x, long n) {
    if (n == 0)
      return 1;

    double half = helper(x, n / 2);
    if (n % 2 == 0) {
      return half * half;
    } else {
      return half * half * x;
    }
  }
};
