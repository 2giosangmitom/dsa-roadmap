#pragma once

class Solution {
 public:
  // Digital root
  int addDigits(int num) {
    if (num == 0) return 0;
    return 1 + ((num - 1) % 9);
  }
};
