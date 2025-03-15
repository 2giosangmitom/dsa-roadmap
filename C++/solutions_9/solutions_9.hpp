#pragma once

class Solution {
public:
  bool isPalindrome(int x) {
    // Negative numbers and numbers ending in 0 (except 0 itself) are not
    // palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int reversed_half = 0;
    while (x > reversed_half) {
      reversed_half = reversed_half * 10 + x % 10;
      x /= 10;
    }

    // For numbers with an odd number of digits, we can get rid of the middle
    // digit by reversed_half / 10
    return x == reversed_half || x == reversed_half / 10;
  }
};
