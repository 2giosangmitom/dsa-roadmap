#pragma once

#include <functional>
#include <queue>
using namespace std;

class MedianFinder {
 private:
  priority_queue<int> left_half;                           // Max-heap
  priority_queue<int, vector<int>, greater<>> right_half;  // Min-heap

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (!left_half.empty() && left_half.top() >= num) {
      left_half.push(num);

      if (left_half.size() > right_half.size() + 1) {
        right_half.push(left_half.top());
        left_half.pop();
      }
    } else {
      right_half.push(num);

      if (right_half.size() > left_half.size()) {
        left_half.push(right_half.top());
        right_half.pop();
      }
    }
  }

  double findMedian() {
    if ((left_half.size() + right_half.size()) % 2 == 0) {
      return (left_half.top() + right_half.top()) / 2.0;
    }
    return left_half.top();
  }
};
