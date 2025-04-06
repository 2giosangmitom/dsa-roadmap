#pragma once

#include <functional>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
  priority_queue<int> left_half;                             // Max heap
  priority_queue<int, vector<int>, greater<int>> right_half; // Min heap

public:
  MedianFinder() {}

  void addNum(int num) {
    if (left_half.empty() || num <= left_half.top()) {
      left_half.push(num);

      // Rebalance the heaps
      if (left_half.size() > right_half.size() + 1) {
        right_half.push(left_half.top());
        left_half.pop();
      }
    } else {
      right_half.push(num);

      // Rebalance the heaps
      if (right_half.size() > left_half.size() + 1) {
        left_half.push(right_half.top());
        right_half.pop();
      }
    }
  }

  double findMedian() {
    if (left_half.size() == right_half.size()) {
      return (left_half.top() + right_half.top()) / 2.0;
    }
    return left_half.size() > right_half.size() ? left_half.top()
                                                : right_half.top();
  }
};
