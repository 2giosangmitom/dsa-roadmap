#include "happy_number.hpp"

int Solution::nextNum(int current) {
  int result = 0;
  while (current > 0) {
    int lastDigit = current % 10;
    result += lastDigit * lastDigit;
    current /= 10;
  }
  return result;
}

bool Solution::isHappy(int n) {
  int slow = n;
  int fast = n;

  do {
    slow = nextNum(slow);
    fast = nextNum(nextNum(fast));

    if (fast == 1) {
      return true;
    }
  } while (slow != fast);

  return false;
}
