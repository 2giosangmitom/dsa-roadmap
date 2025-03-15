#pragma once

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int result = 0;
    while (numBottles >= numExchange) {
      int remainder = numBottles % numExchange;
      result += numBottles - remainder;
      numBottles = numBottles / numExchange + remainder;
    }
    result += numBottles;
    return result;
  }
};
