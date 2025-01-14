#ifndef TWO_SUM_HPP
#define TWO_SUM_HPP

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hashMap;

    for (size_t i = 0; i < nums.size(); i++) {
      int remainder = target - nums[i];

      if (hashMap.find(remainder) == nullptr) {
        hashMap.insert({nums[i], i});
      } else {
        return vector<int>{hashMap[remainder], static_cast<int>(i)};
      }
    }

    return vector<int>{};
  }
};

#endif // !TWO_SUM_HPP
