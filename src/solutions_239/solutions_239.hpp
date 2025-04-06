#pragma once

#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<pair<int, int>> deque;
    vector<int> result;
    size_t left = 0;

    for (size_t right = 0; right < nums.size(); right++) {
      while (!deque.empty() && deque.back().first <= nums[right]) {
        deque.pop_back();
      }

      deque.push_back({nums[right], right});

      if (static_cast<int>(right - left + 1) == k) {
        while (!deque.empty() &&
               deque.front().second < static_cast<int>(left)) {
          deque.pop_front();
        }

        result.push_back(deque.front().first);
        left++;
      }
    }

    return result;
  }
};
